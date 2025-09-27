#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif


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

#define MOD 1000000007
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
    int a[n], ind[n];
    memset(ind, -1, sizeof ind);
    int ps[n + 1];
    memset(ps, 0, sizeof ps);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > -1)
            ind[a[i]] = i;
        ps[i + 1] = ps[i] + (a[i] == -1);
    }

    auto get = [&](int l, int r) {
        return ps[r + 1] - ps[l];
    };

    Z fr[n + 2];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            fr[get(i, j)] += 1;
        }
    }

    Z ans = 0;

    int c2 = 0;
    int k = 0;

    auto calc = [&](int c1) {
        int t = ps[n];
        Z val = ncr(c1, c2) * fact[c2] * fact[t - c2];
        return val;
    };

    auto calcall = [&]() {
        Z x = 0;
        for (int in = 0; in <= n; in++) {
            x += calc(in) * fr[in];
        }
        return x;
    };

    while (k < n && ind[k] == -1) k++;

    for (int i = 0; i < k; i++) {
        c2 = i + 1;
        ans += calcall();
    }

    if (k < n) {
        debug(k);
        int l = ind[k], r = ind[k];
        assert(ind[k] != -1);
        for (int i = 0; i <= n; i++) fr[i] = 0;
        for (int i = 0; i <= l; i++) {
            for (int j = r; j < n; j++) {
                fr[get(i, j)] += 1;
            }
        }

        ans += calcall();

        k++;
        while (k < n) {
            debug(k);
            if (ind[k] != -1) {
                for (int i = ind[k] + 1; i <= l; i++) {
                    for (int j = r; j < n; j++) {
                        fr[get(i, j)] -= 1;
                    }
                }
                for (int i = 0; i <= l; i++) {
                    for (int j = r; j < ind[k]; j++) {
                        fr[get(i, j)] -= 1;
                    }
                }
                l = min(l, ind[k]);
                r = max(r, ind[k]);
            } else {
                c2++;
            }

            ans += calcall();

            k++;
        }
    }

    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    build_fact(5050);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("-----", t);
        solve();
    }

    return 0;
}
