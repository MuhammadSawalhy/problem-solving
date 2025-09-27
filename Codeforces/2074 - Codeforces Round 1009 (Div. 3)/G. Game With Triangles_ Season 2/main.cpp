#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define maxit(x, y) (x = max(x, y))

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif


const int N = 404;
int dp[N][N];
int n, a[N];

int mod;
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

using Z = mint;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    mod = n;
    for (int l = 3; l <= n; l++) {
        for (int i = 0; i < n; i++) {
            Z I = i;
            Z J = (I + l - 1);
            for (int k = i; k < i + l - 1; k++) {
                maxit(dp[I.x][l], dp[(I).x][k - i + 1] + dp[(I + k - i + 1).x][l - (k - i + 1)]);
            }
            debug(I, l);
            debug(dp[I.x][l]);
            int val = a[I.x] * a[J.x];
            for (int k = i + 1; k < i + l - 1; k++) {
                Z K = k;
                int cur = val * a[K.x];
                maxit(dp[I.x][l], cur + dp[(I + 1).x][k - i - 1] + dp[(K + 1).x][l - (k - i + 1) - 1]);
                debug(K.x, dp[I.x][l]);
            }
        }
    }

    cout << dp[0][n] << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("-----------------", t);
        solve();
    }

    return 0;
}
