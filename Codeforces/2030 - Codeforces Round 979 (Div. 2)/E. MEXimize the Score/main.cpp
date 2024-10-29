// ﷽
// https://codeforces.com/contest/2030/problem/E

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
using Z = mint<MOD>;

vector<Z> fact = {1};
vector<Z> fact_inv = {1};

void build_fact(int n = 1e6) {
    while ((int) fact.size() < n + 1)
        fact.push_back(fact.back() * (int) fact.size());
    fact_inv.resize(fact.size());
    fact_inv.back() = fact.back().inv();
    for (int j = fact_inv.size() - 2; fact_inv[j].x == 0; j--)
        fact_inv[j] = fact_inv[j + 1] * (j + 1);
}

Z ncr(int n, int r) {
    if (r > n || r < 0) return 0;
    if ((int) fact.size() < n + 1) build_fact(n);
    return fact[n] * fact_inv[r] * fact_inv[n - r];
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> fr(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        fr[a[i]]++;
    }

    Z ans = 0, dp[2][n + 1], cnt[2][n + 1];

    int prv = 0 & 1, cur = prv ^ 1;
    for (int j = 0; j <= fr[0]; j++) {
        dp[cur][j] = ncr(fr[0], j) * j;
        cnt[cur][j] = ncr(fr[0], j);
        ans += dp[cur][j];
        debug(0, j, dp[cur][j], cnt[cur][j]);
    }

    for (int i = 1; i <= n; i++) {
        int prv = i & 1, cur = prv ^ 1;
        if (i > 1)
            for (int j = 0; j <= fr[i - 2]; j++) {
                cnt[cur][j] = 0;
                dp[cur][j] = 0;
            }

        Z nc = Z(2).power(fr[i]);
        Z sum = 0, sum2 = 0;
        Z cntsum = 0;

        for (int j = 1; j <= fr[i - 1]; j++) {
            cntsum += cnt[prv][j];
            sum += dp[prv][j];
        }

        dp[cur][0] += dp[prv][0] * nc;
        cnt[cur][0] += cnt[prv][0] * nc;
        dp[cur][0] += sum * ncr(fr[i], 0);
        cnt[cur][0] += cntsum * ncr(fr[i], 0);

        debug(i, 0, dp[cur][0], cnt[cur][0]);

        nc -= ncr(fr[i], 0);

        for (int j = 1; j <= fr[i]; j++) {
            // cnt[cur][j] += (cnt[prv][j] + cnt[prv][j + 1] + ...) * ncr(fr[i], j);
            // dp[cur][j] += (j * cntsum + dp[prv][j] + dp[prv][j + 1] + ...) * ncr(fr[i], j)
            cnt[cur][j] += cntsum * ncr(fr[i], j);
            dp[cur][j] += (j * cntsum + sum) * ncr(fr[i], j);
            cntsum -= cnt[prv][j];
            sum -= dp[prv][j];
            nc -= ncr(fr[i], j);

            dp[cur][j] += (j * cnt[prv][j] + dp[prv][j]) * nc;
            cnt[cur][j] += cnt[prv][j] * nc;

            if (j > 0) ans += dp[cur][j];
            debug(i, j, dp[cur][j], cnt[cur][j]);
        }
    }

    cout << dp[n & 1 ^ 1][0] << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
