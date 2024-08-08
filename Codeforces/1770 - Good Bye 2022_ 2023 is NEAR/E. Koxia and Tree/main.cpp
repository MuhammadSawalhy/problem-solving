// ﷽
// https://codeforces.com/contest/1770/problem/E

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

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
using Z = mint<MOD>;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> adj[n], sum(n), parent(n);
    vector<Z> p(n);
    Z ans = 0;

    for (int i = 0, u; i < k; i++) {
        cin >> u, u--;
        p[u] = 1;
    }

    function<void(int, int)> dfs = [&](int i, int par) {
        sum[i] = p[i].x;
        parent[i] = par;
        for (auto j: adj[i]) {
            if (j == par) continue;
            dfs(j, i);
            sum[i] += sum[j];
        }
    };

    vector<pair<int, int>> edges;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    dfs(0, -1);

    for (auto [u, v]: edges) {
        // u -> v
        if (parent[u] == v) swap(u, v);
        debug(u, v, p[u] * 2, p[v] * 2);

        ans += sum[v] * (k - sum[v]);

        Z puv = p[u] * (1 - p[v]) / 2;
        Z pvu = p[v] * (1 - p[u]) / 2;

        int deltauv = ((k - sum[v] - 1) - sum[v]);
        int deltavu = ((sum[v] - 1) - (k - sum[v]));

        debug(puv * 4, deltauv);
        debug(pvu * 4, deltavu);

        ans += puv * deltauv;
        ans += pvu * deltavu;

        p[v] += puv - pvu;
        p[u] += pvu - puv;
    }

    cout << ans / (Z(k) * (k - 1) / 2) << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
