// ﷽
// https://codeforces.com/contest/2035/problem/D

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

bool issmaller(int a, int b, int c, int d) {
    if (a == c) return b < d;

    int lsta = 64 - __builtin_clzll(a) + b;
    int lstc = 64 - __builtin_clzll(c) + d;

    if (lsta < lstc) return true;
    if (lsta > lstc) return false;

    return (a << b) < (c << d);
}

void solve() {
    int n;
    cin >> n;
    vector<pii> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int cnt = 0;

        while (x % 2 == 0) {
            x /= 2;
            cnt++;
        }

        a.push_back({x, cnt});
    }

    debug(a);

    vii st;
    Z sum = 0;
    for (int i = 0; i < n; i++) {
        while (st.size() && issmaller(st.back().first, 0, a[i].first, a[i].second)) {
            sum -= st.back().first * Z(2).power(st.back().second);
            a[i].second += st.back().second;
            // trailing zeros
            a[i].second += __builtin_ctzl(st.back().first);
            sum += st.back().first >> __builtin_ctzl(st.back().first);
            st.pop_back();
        }

        debug(a[i]);
        if (st.size()) debug(st.back());

        st.push_back({a[i].first, a[i].second});
        sum += a[i].first * Z(2).power(a[i].second);
        cout << sum << ' ';
    }
    cout << endl;
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
