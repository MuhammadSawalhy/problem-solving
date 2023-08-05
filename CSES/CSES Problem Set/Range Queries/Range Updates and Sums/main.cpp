// ﷽
// https://cses.fi/problemset/task/1735
// CSES -> CSES Problem Set -> Range Updates and Sums

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

// relative updates have to be linear
struct CustomUpdate {
    enum State { idle,
                 relative,
                 forced };

    State state = idle;
    long long value = 0;

    CustomUpdate() = default;
    CustomUpdate(long long value, State s = forced) : value(value), state(s){};

    inline CustomUpdate &operator+=(const CustomUpdate &other) {
        if (state == idle || other.state == forced) {
            value = other.value;
            state = other.state;
        } else {
            assert(other.state == relative);
            value += other.value;
        }
        return *this;
    }
};

template<typename Update = CustomUpdate>
struct CustomValue {
    long long sum = 0, mn = 1e18, mx = -1e18, cnt = 1;

    CustomValue() = default;
    CustomValue(ll value) { sum = mn = mx = value; }

    inline void operator+=(const Update &up) {
        if (up.state == Update::relative)
            sum += up.value * cnt, mn += up.value, mx += up.value;
        else
            sum = up.value * cnt, mn = up.value, mx = up.value;
    }

    inline CustomValue operator+(const CustomValue &other) const {
        CustomValue ans;
        ans.sum = sum + other.sum;
        ans.mn = min(mn, other.mn);
        ans.mx = max(mx, other.mx);
        ans.cnt = cnt + other.cnt;
        return ans;
    }
};

template<typename Value, typename Update>
struct Node {
    Update up;
    Value value;
    int l = -1, r = -1; // [l, r]

    Node() = default;
    Node(int l, int r, const Value &value) : l(l), r(r) { update(value); };

    void update(const Update &up) {
        this->up += up; // accumulate updates
    }

    void apply_update() {
        this->value += up;
        up.state = Update::idle;
    }
};

template<typename Value, typename Update>
struct Segtree {
    int n;
    vector<Node<Value, Update>> tree;

    Segtree(int n) {
        if ((n & (n - 1)) != 0)
            n = 1 << (32 - __builtin_clz(n));
        this->n = n;
        tree.assign(n << 1, Node<Value, Update>());
        for (int i = n; i < n << 1; i++)
            tree[i].l = tree[i].r = i - n;
        for (int i = n - 1; i > 0; i--)
            tree[i].l = tree[i << 1].l, tree[i].r = tree[i << 1 | 1].r;
    }

    Segtree(const vector<Update> &values) : Segtree(values.size()) {
        for (int i = 0; i < (int) values.size(); i++)
            tree[i + n].update(values[i]), push(i + n);
        build();
    }

    void build() {
        for (int i = n - 1; i > 0; --i) pull(i);
    }

    inline Value query(int i) { return query(1, i, i); }
    inline Value query(int i, int j) { return query(1, i, j); }
    inline void update(int i, const Update &val) { update(1, i, i, val); }
    inline void update(int i, int j, const Update &val) { update(1, i, j, val); }

private:
    void pull(int i) {
        tree[i].value = tree[i << 1].value + tree[i << 1 | 1].value;
    }

    void push(int i) {
        int left = i << 1, right = i << 1 | 1;
        if (tree[i].up.state != Update::idle) {
            if (i < n) tree[left].update(tree[i].up);
            if (i < n) tree[right].update(tree[i].up);
            tree[i].apply_update();
        }
    }

    Value query(int i, int l, int r) {
        push(i);
        if (tree[i].r < l || r < tree[i].l) return Value(); // default
        if (l <= tree[i].l && tree[i].r <= r) return tree[i].value;
        return query(i << 1, l, r) + query(i << 1 | 1, l, r);
    }

    void update(int i, int l, int r, const Update &val) {
        push(i);
        if (tree[i].r < l || r < tree[i].l) return;
        if (l <= tree[i].l && tree[i].r <= r) {
            tree[i].update(val);
            push(i); // to apply the update
            return;
        }
        update(i << 1, l, r, val);
        update(i << 1 | 1, l, r, val);
        pull(i);
    }
};

using Update = CustomUpdate;
using Value = CustomValue<Update>;
using SegTREE = Segtree<Value, Update>;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<Update> values(n);
    for (int i = 0, a; i < n; i++) cin >> a, values[i] = a;

    SegTREE sg(values);

    while (q--) {
        int t, a, b, x;
        cin >> t >> a >> b, a--, b--;
        if (t == 1) {
            cin >> x;
            sg.update(a, b, Update(x, Update::relative));
        } else if (t == 2) {
            cin >> x;
            sg.update(a, b, x);
        } else {
            cout << sg.query(a, b).sum << endl;
        }
    }

    return 0;
}
