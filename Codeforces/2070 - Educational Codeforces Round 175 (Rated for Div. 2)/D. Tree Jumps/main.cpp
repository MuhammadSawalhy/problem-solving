#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)


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
        assert(b >= 0);
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
using Z = mint<MOD>;


void solve() {
    int n;
    cin >> n;
    vector<int> adj[n];
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p, p--;
        adj[p].push_back(i);
    }

    vector<int> depth(n + 1);
    vector<int> nodes[n + 1];

    function<void(int, int)> dfs = [&](int i, int d) {
        depth[i] = d;
        nodes[d].push_back(i);
        for (auto j: adj[i]) {
            dfs(j, d + 1);
        }
    };

    dfs(0, 0);

    vector<Z> dp(n);
    vector<Z> sum(n + 1);

    for (int d = n - 1; d > 0; d--) {
        for (auto i: nodes[d]) {
            dp[i] = sum[d + 1] + 1;
            for (auto j: adj[i]) dp[i] -= dp[j];
            sum[d] += dp[i];
        }
    }

    dp[0] = sum[0] = sum[1] + 1;

    cout << sum[0] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
