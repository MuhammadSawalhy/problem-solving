#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ll long long
#define minit(a, b) a = min(a, b)

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

struct Value;
struct Update;
struct Node;

ll inf = 1e18;
int a[4];

// Replaceable by primitives (using Value = long long)
struct Value {
    long long sum = 0, max1 = -inf, max2 = -inf, mcnt = 0;
    Value() = default;
    Value(ll value) { sum = max1 = value, mcnt = 1; }

    Value &operator+=(const Value &other) {
        sum += other.sum;
        if (max1 > other.max1) {
            max2 = max(max2, other.max1);
        } else if (max1 == other.max1) {
            mcnt += other.mcnt;
            max2 = max(max2, other.max2);
        } else {
            max2 = max(max1, other.max2);
            max1 = other.max1;
            mcnt = other.mcnt;
        }
        return *this;
    }

    Value operator+(const Value &other) const {
        return Value(*this) += other;
    }
};

struct Update {
    // NOTE: Sometime you need to split the update, in these cases
    // you should include the range [a, b] of the update in the struct Update
    int value;
    enum State {
        idle,
        relative,
        forced
    } state = idle;

    Update() = default;
    Update(int value, State state = forced) : value(value), state(state) {};

    Update &operator+=(const Update &other) {
        if (state == idle || other.state == forced) {
            *this = other;
        } else {
            assert(other.state == relative);
            minit(value, other.value); // NOTE: merge updates
        }
        return *this;
    }

    void apply_on(Value &other, int cnt) const {
        assert(value < other.max1 && value > other.max2);
        other.sum += 1LL * (value - other.max1) * (other.mcnt);
        other.max1 = value;
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
        if (l <= tree[i].l && tree[i].r <= r) {
            return tree[i].value;
        }
        return query(i << 1, l, r) + query(i << 1 | 1, l, r);
    }

    void update(int i, int l, int r, const Update &up) {
        push(i);
        if (tree[i].r < l || r < tree[i].l || up.value >= tree[i].value.max1) return;
        if (l <= tree[i].l && tree[i].r <= r && up.value < tree[i].value.max1 && up.value > tree[i].value.max2) {
            tree[i].update(up);
            tree[i].apply_update();
            return;
        }
        update(i << 1, l, r, up.get(tree[i << 1]));
        update(i << 1 | 1, l, r, up.get(tree[i << 1 | 1]));
        pull(i);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    Segtree sg(n);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        sg.tree[sg.n + i].value = Value(x);
    }
    sg.build();

    debug(sg.tree[1].value.sum);

    while (m--) {
        int type, x, y;
        cin >> type >> x >> y, x--, y--;
        if (type == 0) {
            int t;
            cin >> t;
            sg.update(x, y, Update(t));
        } else if (type == 1) {
            cout << sg.query(x, y).max1 << '\n';
        } else if (type == 2) {
            cout << sg.query(x, y).sum << '\n';
        }
    }
    return;
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
