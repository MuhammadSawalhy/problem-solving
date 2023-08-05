// ﷽
// https://cses.fi/problemset/task/1190
// CSES -> CSES Problem Set -> Subarray Sum Queries

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

const int inf = 1e18;

// relative updates have to be linear
struct CustomRelativeUpdate {
    static const long long initial = 0;
    long long value = initial;

    CustomRelativeUpdate() = default;
    CustomRelativeUpdate(long long value) : value(value){};

    inline CustomRelativeUpdate &operator+=(const CustomRelativeUpdate &other) {
        value = value + other.value;
        return *this;
    }
};

template<typename RelativeUpdate = CustomRelativeUpdate>
struct CustomValue {
    long long sum = 0, mn = 0, mx = 0, value = 0;

    CustomValue() = default;
    CustomValue(ll val) { sum = mx = val, mn = min(0ll, val), value = max(val, 0LL); }

    // Node is responsible for applying the relative update
    inline CustomValue &operator+=(const RelativeUpdate &rel) {
        // sum += cnt * rel.value, mn += rel.value, mx += rel.value;
        return *this;
    }

    inline CustomValue operator+(const CustomValue &other) const {
        CustomValue ans;
        ans.mn = min(mn, sum + other.mn);
        ans.mx = max(mx, sum + other.mx);
        ans.sum = sum + other.sum;
        ans.value = max({ value, other.value, sum + other.mx - mn });
        return ans;
    }
};

template<typename Value, typename RelativeUpdate>
struct Node {
    Value value; // shouldn't be edited directly, only in pull function
    RelativeUpdate rel;

    int l = -1, r = -1; // [l, r]
    bool pending_update = false;
    bool pending_relative_update = false;

    Node() = default;
    Node(int l, int r, const Value &value) : l(l), r(r) { update(value); };

    void update(const Value &value) {
        this->value = value;
        this->rel = RelativeUpdate(); // reset
        pending_update = true;
        pending_relative_update = false;
    }

    void relative_update(const RelativeUpdate rel) {
        // we need this to be pushed later to the children
        this->rel += rel;
        pending_relative_update = true;
    }

    void apply_relupdate() {
        value += rel;
    }
};

template<typename Value, typename RelativeUpdate>
struct Segtree {
    int n;
    vector<Node<Value, RelativeUpdate>> tree;

    Segtree(int n) {
        if ((n & (n - 1)) != 0)
            n = 1 << (32 - __builtin_clz(n));
        this->n = n;
        tree.assign(n << 1, Node<Value, RelativeUpdate>());
        for (int i = n; i < n << 1; i++)
            tree[i].l = tree[i].r = i - n;
        for (int i = n - 1; i > 0; i--)
            tree[i].l = tree[i << 1].l, tree[i].r = tree[i << 1 | 1].r;
    }

    Segtree(const vector<Value> &values) : Segtree(values.size()) {
        for (int i = 0; i < (int) values.size(); i++)
            tree[i + n].update(values[i]);
        build();
    }

    void build() {
        for (int i = n - 1; i > 0; --i) pull(i);
    }

    inline Value query(int i) { return query(1, i, i); }

    inline Value query(int i, int j) { return query(1, i, j); }

    inline void update(int i, const Value &val) { update(1, i, i, val); }

    inline void update(int i, int j, const Value &val) { update(1, i, j, val); }

    inline void relative_update(int i, const RelativeUpdate &val) {
        relative_update(1, i, i, val);
    }

    inline void relative_update(int i, int j, const RelativeUpdate &val) {
        relative_update(1, i, j, val);
    }

private:
    void pull(int i) {
        tree[i].value = tree[i << 1].value + tree[i << 1 | 1].value;
    }

    void push(int i) {
        int left = i << 1, right = i << 1 | 1;

        if (tree[i].pending_update) {
            if (i < n) tree[left].update(tree[i].value);
            if (i < n) tree[right].update(tree[i].value);
            tree[i].pending_update = false;
        }

        if (tree[i].pending_relative_update) {
            if (i < n) tree[left].relative_update(tree[i].rel);
            if (i < n) tree[right].relative_update(tree[i].rel);
            tree[i].apply_relupdate();
            tree[i].rel = RelativeUpdate(); // reset
            tree[i].pending_relative_update = false;
        }
    }

    Value query(int i, int l, int r) {
        push(i);
        if (tree[i].r < l || r < tree[i].l) return Value(); // default
        if (l <= tree[i].l && tree[i].r <= r) return tree[i].value;
        return query(i << 1, l, r) + query(i << 1 | 1, l, r);
    }

    void update(int i, int l, int r, const Value &val) {
        push(i);
        if (tree[i].r < l || r < tree[i].l) return;
        if (l <= tree[i].l && tree[i].r <= r) {
            tree[i].update(val);
            return;
        }
        update(i << 1, l, r, val);
        update(i << 1 | 1, l, r, val);
        pull(i);
    }

    void relative_update(int i, int l, int r, const RelativeUpdate &val) {
        push(i);
        if (tree[i].r < l || r < tree[i].l) return;
        if (l <= tree[i].l && tree[i].r <= r) {
            tree[i].relative_update(val);
            push(i); // to apply the rel update and update ancestors
            return;
        }
        relative_update(i << 1, l, r, val);
        relative_update(i << 1 | 1, l, r, val);
        pull(i);
    }
};

using RelativeUpdate = CustomRelativeUpdate;
using Value = CustomValue<RelativeUpdate>;
using SegTREE = Segtree<Value, RelativeUpdate>;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    SegTREE sg(n);
    for (size_t i = 0; i < n; i++) {
        int a;
        cin >> a;
        sg.update(i, a);
    }

    while (q--) {
        int i, x;
        cin >> i >> x, i--;
        sg.update(i, x);
        cout << sg.query(0, n - 1).value << '\n';
    }

    return 0;
}
