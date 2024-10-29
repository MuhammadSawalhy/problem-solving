// ﷽
// https://csacademy.com/ieeextreme18/task/increasing-table/

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

void solve() {
    int n;
    cin >> n;

    int x;
    cin >> x;
    vi a(x);
    set<int> A;

    for (auto &u: a) {
        cin >> u;
        A.insert(u);
    }

    int y;
    cin >> y;
    vi b(y);
    set<int> B;
    for (auto &u: b) {
        cin >> u;
        B.insert(u);
    }

    Z dp[n + 1][n + 1];
    dp[0][0] = 1;

    for (int x = 0; x < 2 * n; x++) {
        for (int j = 0; j <= x / 2; j++) {
            int i = x - j;
            if (i > n || j > n) continue;
            bool canUp = i + 1 <= n && !B.count(x + 1);
            bool canDown = j + 1 <= n && j + 1 <= i && !A.count(x + 1);

            if (canUp) {
                dp[i + 1][j] += dp[i][j];
            }

            if (canDown) {
                dp[i][j + 1] += dp[i][j];
            }
        }
    }

    cout << dp[n][n] << endl;
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
