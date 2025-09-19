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
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vii vector<pii>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

struct Value;
struct Update;
struct Node;

// Replaceable by primitives (using Value = long long)
struct Value {
    long long mx, total_or, total_and;
    Value() = default;
    Value(ll value) { mx = value, total_or = value, total_and = value; }

    Value &operator+=(const Value &other) {
        mx = max(mx, other.mx);
        total_or |= other.total_or;
        total_and &= other.total_and;
        return *this;
    }

    Value operator+(const Value &other) const {
        return Value(*this) += other;
    }
};

struct Update {
    // NOTE: Sometime you need to split the update, in these cases
    // you should include the range [a, b] of the update in the struct Update
    enum {
        idle,
        normal
    } state = idle;

    int or_value = 0;
    int and_value = -1;

    Update() = default;
    Update(int or_value, int and_value) : or_value(or_value), and_value(and_value), state(normal) {};

    Update &operator+=(const Update &other) {
        if (state == idle) return *this = other;
        or_value &= other.and_value;
        or_value |= other.or_value;
        and_value &= other.and_value;
        and_value |= other.or_value;
        return *this;
    }

    void apply_on(Value &v, int cnt) const {
        v.mx = v.mx | or_value;
        v.mx = v.mx & and_value;
        v.total_or |= or_value;
        v.total_and &= and_value;
    }

    inline bool is_applicable(const Value &v) const {
        ll mask = v.total_and | (~v.total_or);
        return (or_value & mask) == or_value && (~and_value & mask) == ~and_value;
    }

    Update get(const Node &node) const { return *this; }
};

struct Node {
    int l = -1, r = -1; // [l, r]
    Update up;
    Value value;

    Node() = default;
    Node(int l, int r, const Value &value) : l(l), r(r), value(value) {};

    void update(const Update &up) { this->up += up; }

    void apply_update() {
        up.apply_on(value, r - l + 1);
        up.state = Update::idle;
    }
};

struct Segtree {
    int n;
    vector<Node> tree;

    Segtree(int n) {
        if ((n & (n - 1)) != 0)
            n = 1 << (32 - __builtin_clz(n));
        this->n = n;
        tree.assign(n << 1, Node());
        for (int i = n; i < n << 1; i++)
            tree[i].l = tree[i].r = i - n;
        for (int i = n - 1; i > 0; i--)
            tree[i].l = tree[i << 1].l, tree[i].r = tree[i << 1 | 1].r;
    }

    Segtree(const vector<Value> &values) : Segtree(values.size()) {
        for (int i = 0; i < (int) values.size(); i++)
            tree[i + n].value = values[i];
        build();
    }

    void build() {
        for (int i = n - 1; i > 0; --i) pull(i);
    }

    inline Value query(int i, int j) { return query(1, i, j); }
    inline void update(int i, int j, const Update &val) { update(1, i, j, val); }

    void pull(int i) {
        tree[i].value = tree[i << 1].value + tree[i << 1 | 1].value;
    }

    void push(int i) {
        if (tree[i].up.state != Update::idle) {
            if (i < n) {
                int l = i << 1, r = i << 1 | 1;
                tree[l].update(tree[i].up.get(tree[l]));
                tree[r].update(tree[i].up.get(tree[r]));
            }
            tree[i].apply_update();
        }
    }

    Value query(int i, int l, int r) {
        push(i);
        if (tree[i].r < l || r < tree[i].l) return Value(); // default
        if (l <= tree[i].l && tree[i].r <= r) return tree[i].value;
        return query(i << 1, l, r) + query(i << 1 | 1, l, r);
    }

    void update(int i, int l, int r, const Update &up) {
        push(i);
        if (tree[i].r < l || r < tree[i].l) return;
        if (l <= tree[i].l && tree[i].r <= r && up.is_applicable(tree[i].value)) {
            debug(i, tree[i].value.mx);
            tree[i].update(up);
            push(i); // to apply the update
            debug(i, tree[i].value.mx);
            return;
        }
        update(i << 1, l, r, up.get(tree[i << 1]));
        update(i << 1 | 1, l, r, up.get(tree[i << 1 | 1]));
        pull(i);
    }
};

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    Segtree tree(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree.tree[tree.n + i].value = Value(x);
    }

    tree.build();

    while (q--) {
        int type, l, r;
        cin >> type >> l >> r, l--, r--;
        if (type == 1) {
            int x;
            cin >> x;
            tree.update(l, r, Update(0, x));
        } else if (type == 2) {
            int x;
            cin >> x;
            tree.update(l, r, Update(x, -1));
        } else {
            cout << tree.query(l, r).mx << endl;
        }
    }

    return 0;
}
