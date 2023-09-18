// ﷽
// https://codeforces.com/contest/1872/problem/G
// Codeforces -> Codeforces Round 895 (Div. 3) -> G. Replace With Product

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

struct Value;
struct Update;
struct Node;

// Replaceable by primitives (using Value = long long)
struct Value {
    long long product = 1, cost = 1e18, index;
    Value() = default;
    Value(ll product, ll index) : product(product), cost(0), index(index) {}

    Value &operator+=(const Value &other) {
        if (product - cost < other.product - other.cost)
            *this = other;
        return *this;
    }

    Value operator+(const Value &other) const {
        return Value(*this) += other;
    }
};

struct Update {
    // NOTE: Sometime you need to split the update, in these cases
    // you should include the range [a, b] of the update in the struct Update
    ll product = 1, cost = 0;
    enum State {
        idle,
        relative,
    } state = idle;

    Update() = default;
    Update(ll product, ll cost, State state = relative) : product(product), cost(cost), state(state){};

    Update &operator+=(const Update &other) {
        if (state == idle) {
            *this = other;
        } else {
            product *= other.product;
            cost += other.cost;
        }
        return *this;
    }

    void apply_on(Value &other, int cnt) const {
        other.product *= product;
        other.cost += cost;
    }

    Update get(const Node &node) const { return *this; }
};

struct Node {
    int l = -1, r = -1; // [l, r]
    Update up;
    Value value;

    Node() = default;
    Node(int l, int r, const Value &value) : l(l), r(r), value(value){};

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

    inline Value query(int i) { return query(1, i, i); }
    inline Value query(int i, int j) { return query(1, i, j); }
    inline void update(int i, const Update &val) { update(1, i, i, val); }
    inline void update(int i, int j, const Update &val) { update(1, i, j, val); }

    void pull(int i) {
        tree[i].value = tree[i << 1].value + tree[i << 1 | 1].value;
    }

private:
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
        if (l <= tree[i].l && tree[i].r <= r) {
            tree[i].update(up);
            push(i); // to apply the update
            return;
        }
        update(i << 1, l, r, up.get(tree[i << 1]));
        update(i << 1 | 1, l, r, up.get(tree[i << 1 | 1]));
        pull(i);
    }
};

void solve() {
    int n;
    cin >> n;
    int a[n];

    int mx = 0;
    int x = 0, y = 0;

    Segtree sg(n);
    int cnt = 0;

    debug(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            if (cnt == 0) continue;
            sg.update(0, cnt - 1, Update(1, 1));
        } else {
            cnt++;
            sg.tree[sg.n + cnt - 1].value = Value(1, i);
            for (int i = sg.n + cnt - 1; i > 1; i /= 2)
                sg.pull(i / 2);
            sg.update(0, cnt - 1, Update(a[i], a[i]));

            auto q = sg.query(0, 0);
            debug(q.product, q.cost, q.index);
            if (q.product - q.cost > mx) {
                mx = q.product - q.cost;
                debug(q.index);
                x = q.index, y = i;
            }
        }
    }

    cout << x + 1 << ' ' << y + 1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
