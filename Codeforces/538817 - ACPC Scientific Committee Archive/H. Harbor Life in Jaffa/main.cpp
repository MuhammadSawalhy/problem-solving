// ﷽
// https://codeforces.com/group/Rilx5irOux/contest/538817/problem/H

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

const int bits = 20;

struct XORBasis {
    array<int, bits> basis{};

    void reset() { basis = array<int, bits>(); }

    void insert(const vector<int> &v) {
        for (auto x: v) insert(x);
    }

    bool insert(int x) {
        for (int b = bits - 1; x && b >= 0; b--) {
            if (x >> b & 1 ^ 1) continue;
            if (!basis[b]) return basis[b] = x, true;
            x ^= basis[b];
        }
        return false;
    }
};


struct Value;
struct Update;
struct Node;

// Replaceable by primitives (using Value = long long)
struct Value {
    XORBasis xb;
    Value() = default;
    Value(ll value) { xb.insert(value); }

    Value &operator+=(const Value &other) {
        for (int i = bits - 1; i >= 0; i--)
            xb.insert(other.xb.basis[i]);
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
    Update(int value, State state = idle) : value(value), state(state){};

    Update &operator+=(const Update &other) {
        if (state == idle || other.state == forced) {
            *this = other;
        } else {
            assert(other.state == relative);
            value &= other.value;
        }
        return *this;
    }

    void apply_on(Value &other, int cnt) const {
        if (state == forced) other = value;
        else {
            XORBasis xb;
            for (int i = 0; i < bits; i++)
                xb.insert(other.xb.basis[i] & value);
            other.xb = xb;
        }
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
            n = 1ll << (32 - __builtin_clz(n));
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

    Segtree sg(n);
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        sg.update(i, Update(a, Update::forced));
    }

    debug(sg.query(0, 0).xb.basis);
    debug(sg.query(0, 1).xb.basis);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x, l--, r--;
            sg.update(l, r, Update(x, Update::relative));
        } else if (t == 2) {
            int i, x;
            cin >> i >> x, i--;
            sg.update(i, Update(x, Update::forced));
        } else {
            int l, r;
            cin >> l >> r, l--, r--;
            auto basis = sg.query(l, r).xb.basis;

            int mx = 0;
            for (int i = bits - 1; i >= 0; i--) {
                if (basis[i] && (mx >> i & 1) == 0) {
                    mx ^= basis[i];
                }
            }

            cout << mx << endl;
        }
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
