// ﷽
// https://csacademy.com/ieeextreme18/task/queries/

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

struct Value;
struct Update;
struct Node;

// Replaceable by primitives (using Value = long long)
struct Value {
    long long sum = 0, mn = 1e18, mx = -1e18;
    Value() = default;
    Value(ll value) { sum = mn = mx = value; }

    Value &operator+=(const Value &other) {
        sum += other.sum;
        mn = min(mn, other.mn);
        mx = max(mx, other.mx);
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
    Update(int value, State state) : value(value), state(state){};

    Update &operator+=(const Update &other) {
        if (state == idle || other.state == forced) {
            *this = other;
        } else {
            assert(other.state == relative);
            value += other.value; // NOTE: merge updates
        }
        return *this;
    }

    void apply_on(Value &other, int cnt) const {
        // if (state == forced) other = value;
        // else other += value;
        // other.sum += value.sum * (cnt - 1);
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
    int n, q;
    cin >> n >> q;

    Segtree one(n), two(n);

    vector<int> p(n), ind(n);
    for (int i = 0; i < n; i++) cin >> p[i], p[i]--, ind[p[i]] = i;

    while (q--) {
        int t;
        cin >> t;

        if (t == 0) {
            int l, r, c;
            cin >> l >> r >> c;
            l--, r--;
            one.update(l, r, Update(c, Update::relative));
        } else if (t == 1) {
            int l, r, c;
            cin >> l >> r >> c;
            l--, r--;
            two.update(l, r, Update(c, Update::relative));

        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << one.query(l, r).sum << '\n';
        } else if (t == 3) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << two.query(l, r).sum << '\n';
        }
    }
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
