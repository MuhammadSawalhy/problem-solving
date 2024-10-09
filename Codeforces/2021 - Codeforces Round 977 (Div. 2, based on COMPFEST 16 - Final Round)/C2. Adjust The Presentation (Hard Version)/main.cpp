// ﷽
// https://codeforces.com/contest/2021/problem/C1

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
#define vvi vector<vector<int>>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

constexpr int H = 2;
typedef array<int, H> val;
vector<val> B;
const val M = {
        1000000007,
        1444444447,
        // 1000000007,
        // 998244353,
};

val tmp;

val operator*(const val &a, const val &b) {
    for (int i = 0; i < H; i++) tmp[i] = a[i] * b[i] % M[i];
    return tmp;
}

val operator-(const val &a, const val &b) {
    for (int i = 0; i < H; i++) tmp[i] = (a[i] - b[i] + M[i]) % M[i];
    return tmp;
}

val operator+(const val &a, const val &b) {
    for (int i = 0; i < H; i++) tmp[i] = (a[i] + b[i]) % M[i];
    return tmp;
}

val getval(int x) {
    for (int i = 0; i < H; i++) tmp[i] = x % M[i];
    return tmp;
}

void setB(int n) {
    if (B.size() == 0) {
        mt19937 rng(random_device{}());
        B.assign(2, getval(1));
        for (int i = 0; i < H; i++)
            B.back()[i] = uniform_int_distribution<ll>(1, M[i] - 1)(rng);
    }
    while ((int) B.size() <= n) B.push_back(B.back() * B[1]);
}

struct Hash {
    vector<val> h;

    Hash(const vector<int> &s) : h(s.size() + 1) {
        setB(s.size());
        for (int i = 0; i < (int) s.size(); i++)
            h[i + 1] = h[i] * B[1] + getval(s[i]);
    }

    val get(int l, int r) { return h[r + 1] - h[l] * B[r - l + 1]; }
};

struct Value;
struct Update;
struct Node;

// Replaceable by primitives (using Value = long long)
struct Value {
    int cnt = 0;
    val v;
    Value() = default;
    Value(const val &v) : v(v), cnt(1) {}

    Value &operator+=(const Value &other) {
        for (int i = 0; i < H; i++)
            v[i] = (v[i] * B[other.cnt][i] % M[i] + other.v[i]) % M[i];
        cnt += other.cnt;
        return *this;
    }

    Value operator+(const Value &other) const {
        return Value(*this) += other;
    }
};

struct Update {
    // NOTE: Sometime you need to split the update, in these cases
    // you should include the range [a, b] of the update in the struct Update
    Value value;
    enum State {
        idle,
        forced,
        relative,
    } state = idle;

    Update() = default;
    Update(Value value, State state = forced) : value(value), state(state){};

    Update &operator+=(const Update &up) {
        switch (up.state) {
            case relative:
                value += up.value;
                break;
            default:
                *this = up;
        }
        return *this;
    }

    void apply_on(Value &v, int cnt) const {
        if (state == forced) v = value;
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i], a[i]--;
    }

    Hash h(a);

    vector<int> b(m);

    for (int i = 0; i < m; i++) {
        cin >> b[i], b[i]--;
    }

    Segtree seg(m);
    set<int> ind[n];

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (ind[b[i]].empty()) {
            debug(i, b[i]);
            cnt++;
            val v = getval(b[i]) * B[0];
            seg.update(i, i, Update(Value(v), Update::forced));
        }
        ind[b[i]].insert(i);
    }

    debug(a);
    debug(b);

    auto qu = seg.query(0, m - 1);
    debug(qu.cnt);
    debug(qu.v[0], h.get(0, cnt - 1)[0]);
    assert(qu.cnt == cnt);
    assert(cnt <= n);

    if (qu.v == h.get(0, cnt - 1)) cout << "YA\n";
    else cout << "TIDAK\n";

    if (cnt == 1e18) {
        cout << "just test random_device";
    }

    while (q--) {
        // hashing and mantaining b?
        int s, t;
        cin >> s >> t;
        s--, t--;

        if (b[s] != t) {
            if (ind[b[s]].size())
                seg.update(*ind[b[s]].begin(), Update(Value(), Update::forced)), ind[b[s]].erase(s);
            if (ind[b[s]].size())
                seg.update(*ind[b[s]].begin(), Update(Value(getval(b[s]) * B[0]), Update::forced));
            else cnt--;

            b[s] = t;

            if (ind[b[s]].size())
                seg.update(*ind[b[s]].begin(), Update(Value(), Update::forced));
            else cnt++;
            ind[b[s]].insert(s);
            if (ind[b[s]].size())
                seg.update(*ind[b[s]].begin(), Update(Value(getval(b[s]) * B[0]), Update::forced));
        }

        auto qu = seg.query(0, m - 1);
        assert(qu.cnt == cnt);
        assert(cnt <= n);

        if (qu.v == h.get(0, cnt - 1)) cout << "YA\n";
        else cout << "TIDAK\n";
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    setB(3e5);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
