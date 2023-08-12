// ﷽
// https://cses.fi/problemset/task/1736
// CSES -> CSES Problem Set -> Polynomial Queries

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

struct Update;
struct Node;
struct Segtree;

using Value = ll;

struct Update {
    // NOTE: Sometime you need to split the update, in these cases
    // you should include the range [a, b] of the update in the struct Update
    int l = -1, r = -1;
    int bias = 1, inc = 1;

    enum State {
        idle,
        relative,
        forced
    } state = idle;

    Update() = default;
    Update(int l, int r, int bias, int inc, State state = forced) : l(l), r(r), bias(bias), inc(inc), state(state){};

    inline Update &operator+=(const Update &other) {
        if (state == idle || other.state == forced) {
            *this = other;
        } else {
            assert(other.state == relative);
            inc += other.inc;
            bias += other.bias;
        }
        return *this;
    }

    inline void apply_on(Value &other, int cnt) const {
        if (state == forced) {
            other = bias * cnt + inc * (cnt * (cnt - 1) / 2);
        } else {
            other += bias * cnt + inc * (cnt * (cnt - 1) / 2);
        }
    }

    Update get(Node &node) const;
};

struct Node {
    Update up;
    Value value = Value();
    int l = -1, r = -1; // [l, r]

    Node() = default;
    Node(int l, int r, const Value &value) : l(l), r(r), value(value){};

    void update(const Update &up) { this->up += up; }
    void apply_update() {
        up.apply_on(value, up.r - up.l + 1);
        up.state = Update::idle;
    }
};

Update Update::get(Node &node) const {
    Update up = *this;
    int L = up.l;
    up.l = max(up.l, node.l);
    up.r = min(up.r, node.r);
    up.bias += (up.l - L) * inc;
    return up;
}

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

private:
    void pull(int i) {
        tree[i].value = tree[i << 1].value + tree[i << 1 | 1].value;
    }

    void push(int i) {
        int l = i << 1, r = i << 1 | 1;
        if (tree[i].up.state != Update::idle) {
            if (i < n) {
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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    Segtree sg(n);

    for (int i = 0, a; i < n; i++) {
        cin >> a;
        sg.tree[i + sg.n].value = a;
    }

    sg.build();

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        a--, b--;
        if (t == 1) {
            // TRIGGER
            sg.update(a, b, Update(a, b, 1, 1, Update::relative));
        } else {
            cout << sg.query(a, b) << endl;
        }
    }

    return 0;
}
