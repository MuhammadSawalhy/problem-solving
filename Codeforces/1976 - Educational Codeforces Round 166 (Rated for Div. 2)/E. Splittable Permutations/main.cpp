// ﷽
// https://codeforces.com/contest/1976/problem/E

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
    int n, q;
    cin >> n >> q;

    set<int> ex;
    vector<int> th;

    th.push_back(n);
    ex.insert(n);

    Z ans = 1;
    vector<int> left(n + 1, -1), right(n + 1, -1);
    vector<int> l(q), r(q);

    for (int i = 0; i < q; i++) cin >> l[i];
    for (int i = 0; i < q; i++) cin >> r[i];

    for (int i = 0; i < q; i++) {
        bool L = ex.count(l[i]);
        bool R = ex.count(r[i]);

        if (L == R) {
            cout << 0 << endl;
            return;
        }

        if (L) {
            ex.insert(r[i]);
            th.push_back(r[i]);
            // update left of the right
            int myr = right[l[i]];
            if (~myr) {
                left[myr] = r[i];
                right[r[i]] = myr;
            }
        } else {
            assert(R);
            ex.insert(l[i]);
            th.push_back(l[i]);
            int myl = left[r[i]];
            if (~myl) {
                right[myl] = l[i];
                left[l[i]] = myl;
            }
        }

        right[l[i]] = r[i];
        left[r[i]] = l[i];
        debug(left);
        debug(right);
    }

    sort(all(th));

    for (int i = n - 1, p = 0; i >= 1; i--) {
        if (ex.count(i)) {
            int l = left[i], r = right[i];
            if (l > i && r > i) p--;
            else if (l < i && r < i) p++;
            continue;
        }
        debug(i, p);

        // count of (> i) + chasms + 1
        ans *= n - i + p + 1;
    }

    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
