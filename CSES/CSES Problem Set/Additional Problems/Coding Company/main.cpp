// ﷽
// https://cses.fi/problemset/task/1665

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

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(all(a));

    Z dp[n][x + 5001];
    Z newdp[n][x + 5001];
    dp[0][5000] = 1;

    for (int i = 0; i < n; i++) {
        debug(i);

        for (int j = 0; j < n; j++) {
            for (int k = 0; k <= x + 5000; k++) newdp[j][k] = 0;
        }

        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= x + 5000; k++) {
                newdp[j][k] += (j + 1) * dp[j][k];
                if (j + 1 < n && k - a[i] >= 0)
                    newdp[j + 1][k - a[i]] += dp[j][k];
                if (j - 1 >= 0 && k + a[i] <= x + 5000)
                    newdp[j - 1][k + a[i]] += j * dp[j][k];
            }
        }

        for (int j = 0; j < n; j++) {
            for (int k = 0; k <= x + 5000; k++)
                dp[j][k] = newdp[j][k];
        }
    }

    Z ans = 0;
    for (int l = 0; l <= x + 5000; l++) {
        ans += dp[0][l];
    }

    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
