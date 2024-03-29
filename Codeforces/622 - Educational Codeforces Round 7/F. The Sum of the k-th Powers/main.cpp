// ﷽
// https://codeforces.com/contest/622/problem/F

#include <bits/stdc++.h>
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
        return x >= mod ? x - mod
               : x < 0  ? x + mod
                        : x;
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

// constexpr int MOD = 998244353;
constexpr int MOD = 1000000007;
using Z = mint<MOD>;

const int K = 1e6 + 2;
Z y[K], fact[K], invfact[K];

void solve() {
    int n, k;
    cin >> n >> k;

    int v = 0;
    Z ans = 0, cur = (n - 0);

    fact[0] = invfact[0] = 1;

    for (int i = 1; i <= k + 1; i++) {
        fact[i] = fact[i - 1] * i;
    }

    invfact[k + 1] = fact[k + 1].inv();
    for (int i = k; i >= 1; i--) {
        invfact[i] = invfact[i + 1] * (i + 1);
    }

    for (int i = 1; i <= k + 1; i++) {
        y[i] = y[i - 1] + Z(i).power(k);
        cur *= (n - i);
    }

    if (n <= k + 1) {
        return void(cout << y[n] << endl);
    }

    for (int i = 0; i <= k + 1; i++) {
        Z c = cur / (n - i) * y[i];
        // denom 1st part: (xi - x0) * (xi - x1) * ... * (x[i] - x[i - 1])
        // denom 2nd part: (xi - x[i + 1]) * ... * (xi - x[k + 1])
        // xi = i
        Z denom1 = fact[i];
        Z denom2 = fact[k + 1 - i];
        Z cur = c / denom1 / denom2;
        ans += ((k + 1 - i) % 2 == 0 ? cur : -cur);
    }

    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
