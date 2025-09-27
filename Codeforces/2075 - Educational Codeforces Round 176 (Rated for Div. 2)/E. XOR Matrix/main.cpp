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

#define MOD 998244353
using Z = mint<MOD>;
int n, m, A, B;
bool vis[31][2][2][2][2];
Z dp[31][2][2][2][2];

Z calc(int i, bool isx, bool isy, bool isr, bool isz) {
    if (i == -1) return 1;

    auto &ret = dp[i][isx][isy][isr][isz];
    auto &v = vis[i][isx][isy][isr][isz];
    if (v) return ret;
    v = 1;
    ret = 0;

    debug(i, isx, isy, isr, isz);
    for (int x = 0; x <= (isx ? (A >> i & 1) : 1); x++) {
        for (int y = 0; y <= (isy ? (A >> i & 1) : 1); y++) {
            for (int r = 0; r <= (isr ? (B >> i & 1) : 1); r++) {
                for (int z = 0; z <= (isz ? (B >> i & 1) : 1); z++) {
                    if ((x ^ y ^ r ^ z))
                        continue;
                    debug(x,y,r,z);
                    ret += calc(
                            i - 1,
                            isx && (x == (A >> i & 1)),
                            isy && (y == (A >> i & 1)),
                            isr && (r == (B >> i & 1)),
                            isz && (z == (B >> i & 1)));
                }
            }
        }
    }

    return ret;
}

void solve() {
    cin >> n >> m >> A >> B;
    debug(n, m, A, B);
    A++, B++;

    // 1 : 1
    Z ans = Z(A) * Z(B);
    // 1 : 2
    ans += Z(A) * Z(B) * (B - 1) / 2 * (Z(2).power(m) - 2);
    // 2 : 1
    ans += Z(A) * Z(A - 1) / 2 * (Z(2).power(n) - 2) * Z(B);

    // // 2 : 2
    // Z x = 0;
    // for (int i = 0; i < A; i++) {
    //     for (int j = i + 1; j < A; j++) {
    //         for (int k = 0; k < B; k++) {
    //             if ((i ^ j ^ k) < k) {
    //                 x.x++;
    //             }
    //         }
    //     }
    // }

    A--, B--;
    memset(vis, 0, sizeof vis);
    auto x = calc(30, 1, 1, 1, 1);
    A++,B++;
    x -= Z(A) * B;
    debug(x);
    x *= (Z(2).power(n) - 2) * (Z(2).power(m) - 2);
    cout << ans + x / 4 << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
