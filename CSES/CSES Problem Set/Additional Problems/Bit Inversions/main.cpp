// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()

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
    ll prefix[2] = {};
    ll suffix[2] = {};
    ll substr[2] = {};
    int cnt = 1;

    CustomValue() = default;

    inline CustomValue &operator+=(const RelativeUpdate &rel) {
        return *this;
    }

    inline CustomValue operator+(const CustomValue &other) const {
        CustomValue ans;

        ans.prefix[0] = prefix[0] == cnt ? prefix[0] + other.prefix[0] : prefix[0];
        ans.prefix[1] = prefix[1] == cnt ? prefix[1] + other.prefix[1] : prefix[1];

        ans.suffix[0] = other.suffix[0] == cnt ? other.suffix[0] + suffix[0] : other.suffix[0];
        ans.suffix[1] = other.suffix[1] == cnt ? other.suffix[1] + suffix[1] : other.suffix[1];

        ans.substr[0] = max({substr[0], other.substr[0], suffix[0] + other.prefix[0]});
        ans.substr[1] = max({substr[1], other.substr[1], suffix[1] + other.prefix[1]});
        ans.cnt = cnt + other.cnt;

        if (ans.prefix[0]) assert(!ans.prefix[1]);
        if (ans.prefix[1]) assert(!ans.prefix[0]);
        if (ans.suffix[0]) assert(!ans.suffix[1]);
        if (ans.suffix[1]) assert(!ans.suffix[0]);

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
        this->rel += rel;
        pending_relative_update = true;
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
            tree[i].value += tree[i].rel;
            tree[i].rel = RelativeUpdate();
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

Value create_value(char c) {
    Value val;
    int v = c - '0';
    val.prefix[v] = 1;
    val.suffix[v] = 1;
    val.substr[v] = 1;
    return val;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;

    SegTREE sg(s.length());

    for (int i = 0; i < s.length(); i++) {
        sg.update(i, create_value(s[i]));
        debug(i);
    }

    int q;
    cin >> q;
    while (q--) {
        int i;
        cin >> i, i--;
        s[i] = s[i] == '0' ? '1' : '0';
        sg.update(i, create_value(s[i]));
        auto ans = sg.query(0, s.length() - 1);
        cout << max(ans.substr[0], ans.substr[1]) << ' ';
    }

    return 0;
}
