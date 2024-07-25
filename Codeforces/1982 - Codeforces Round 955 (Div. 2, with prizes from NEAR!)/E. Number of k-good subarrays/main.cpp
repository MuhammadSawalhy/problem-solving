// ﷽
// https://codeforces.com/contest/1982/problem/E

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

// constexpr int MOD = 998244353;
constexpr int MOD = 1000000007;
using Z = mint<MOD>;

int floorp2(int x) {
    assert(x != 0);
    int p = 0;
    while ((1ll << p) <= x) {
        p++;
    }
    p--;
    return p;
}

struct Info {
    int l, r;
    Z val;
};

Info merge(const Info &a, const Info &b) {
    Info c;
    c.l = a.l + b.l * (a.l == a.r && a.l != 0);
    c.r = b.r + a.r * (b.l == b.r && b.l != 0);
    c.val = a.val + b.val + Z(a.r) * b.l;
    return c;
}

map<int, Info> cache[61];

// k-good subarray from 0 to x - 1
Info doit(int k, int x) {
    assert(x != 0);
    if (cache[k].count(x)) return cache[k][x];
    Info &res = cache[k][x];

    if (x == 1) return res = {1, 1, 1};
    if (k == 0) return res = {1, 0, 1};

    int p = floorp2(x);
    int y = 1ll << p;

    Info a = doit(k, y / 2);
    Info b = doit(k - 1, y / 2);

    res = merge(a, b);

    if (y != x) {
        Info c = doit(k - 1, x - y);
        res = merge(res, c);
    }

    return res;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    cout << doit(k, n).val << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
