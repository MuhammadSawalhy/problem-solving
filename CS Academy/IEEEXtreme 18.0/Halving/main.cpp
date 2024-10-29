// ﷽
// https://csacademy.com/ieeextreme18/task/halving/

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
    vi a(n * 2);
    set<int> sv, szero, sone;

    for (int i = 0; i < 2 * n; i++) {
        sv.insert(i + 1);
    }

    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        sv.erase(a[i]);
    }

    vi b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vi r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
        sv.erase(r[i]);
    }

    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            szero.insert(r[i]);
        } else {
            sone.insert(r[i]);
        }
    }

    int cntNon = 0;
    Z ans = 0;

    for (int i = 0; i < n; i++) {
        if (a[i * 2] == -1 && a[i * 2 + 1] == -1) {
            cntNon++;
        }
    }

    debug(cntNon);
    debug(sv);

    Z dp[n][n][n];
    dp[0][0][0] = 1;

    vi one(all(sone)), zero(all(szero));
    debug(one);
    debug(zero);


    cout << ans * Z(2).power(cntNon) << endl;
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
