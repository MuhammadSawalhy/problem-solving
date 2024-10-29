// ﷽
// https://codeforces.com/contest/2027/problem/D2

#include <algorithm>
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

template<int32_t mod>
struct mint {
    using Z = mint;
    int32_t x;
    mint(int32_t x = 0) : x(norm(x)) {}
    mint(ll x) : x(norm(x % mod)) {}
    inline int32_t norm(int32_t x) const {
        return x >= mod ? x - mod : (x < 0 ? x + mod : x);
    }
    Z power(ll b) const {
        Z res = 1, a = x;
        for (; b; b >>= 1, a *= a)
            if (b & 1) res *= a;
        return res;
    }
    Z inv() const { return assert(x != 0), power(mod - 2); }
    Z operator-() const { return -x; }
    Z &operator*=(const Z &r) { return *this = (ll) x * r.x; }
    Z &operator+=(const Z &r) { return *this = x + r.x; }
    Z &operator-=(const Z &r) { return *this = x - r.x; }
    Z &operator/=(const Z &r) { return *this *= r.inv(); }
    friend Z operator*(const Z &l, const Z &r) { return Z(l) *= r; }
    friend Z operator+(const Z &l, const Z &r) { return Z(l) += r; }
    friend Z operator-(const Z &l, const Z &r) { return Z(l) -= r; }
    friend Z operator/(const Z &l, const Z &r) { return Z(l) /= r; }
    friend ostream &operator<<(ostream &os, const Z &a) { return os << a.x; }
    friend istream &operator>>(istream &is, Z &a) {
        ll y = 0;
        return is >> y, a = y, is;
    }
};

#define MOD 998244353
#define MOD 1000000007
using Z = mint<MOD>;


pair<int, Z> merge(const pair<int, Z> &l, const pair<int, Z> &r) {
    if (l.first < r.first) return l;
    if (r.first < l.first) return r;
    return {l.first, r.second + l.second};
}

struct Value;
struct Update;
struct Node;

// Replaceable by primitives (using Value = long long)
struct Value {
    pair<int, Z> val{1e18, 0};
    Value() = default;
    Value(pair<int, Z> v) { val = v; }

    Value &operator+=(const Value &other) {
        val = merge(val, other.val);
        return *this;
    }

    Value operator+(const Value &other) const {
        return Value(*this) += other;
    }
};

struct Update {
    // NOTE: Sometime you need to split the update, in these cases
    // you should include the range [a, b] of the update in the struct Update
    pair<int, Z> value;
    enum State {
        idle,
        relative,
        forced
    } state = idle;

    Update() = default;
    Update(pair<int, Z> value, State state) : value(value), state(state){};

    Update &operator+=(const Update &other) {
        if (state == idle || other.state == forced) {
            *this = other;
        } else {
            assert(false);
        }
        return *this;
    }

    void apply_on(Value &other, int cnt) const {
        if (state == forced) other = value;
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
    int n, m;
    cin >> n >> m;

    int a[n];
    int ps[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ps[i] = a[i];
        if (i > 0) ps[i] += ps[i - 1];
    }

    int b[m];
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    pair<int, Z> dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = {1e18, 0};
    dp[0][1] = {0, 1};

    Segtree sg(n + 1);
    for (int k = 1; k <= m; k++) {
        for (int i = 0; i <= n; i++) {
            dp[i][k] = merge(dp[i][k], dp[i][k - 1]);
            sg.update(i, i, Update(dp[i][k], Update::forced));
            if (i == 0) continue;
            if (ps[i - 1] <= b[k - 1]) {
                dp[i][k] = merge(dp[i][k], {dp[0][k].first + m - k, dp[0][k].second});
                sg.update(i, i, Update(dp[i][k], Update::forced));
            } else {
                int x = ps[i - 1] - b[k - 1];
                // x<= ps[asdf] ;
                int j = lower_bound(ps, ps + n, x) - ps + 1;
                if (j >= i) continue;
                auto q = sg.query(j, i);
                dp[i][k] = merge(dp[i][k], {q.val.first + m - k, q.val.second});
                sg.update(i, i, Update(dp[i][k], Update::forced));
                // for (int jj = j; jj < i; jj++) {
                //     dp[i][k] = merge(dp[i][k], {dp[jj][k].first + m - k, dp[jj][k].second});
                // }
            }
        }
    }

    if (dp[n][m].first == 1e18) {
        cout << -1 << endl;
        return;
    }

    cout << dp[n][m].first << endl;
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}

