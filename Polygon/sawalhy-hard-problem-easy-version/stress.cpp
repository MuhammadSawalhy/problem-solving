// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

template<typename T = void>
struct OtherType {
    typedef ll type;
};

template<>
struct OtherType<ll> {
    typedef __int128 type;
};

template<typename T, T mod, typename V = typename OtherType<T>::type>
struct mint {
private:
    T norm(T x) const {
        if (x < 0) x += mod;
        if (x >= mod) x -= mod;
        return x;
    }

public:
    T x;
    T val() const { return x; }
    mint(V x = 0) : x(norm(x % mod)) {}
    mint operator-() const { return mint(norm(mod - x)); }
    mint inv() const {
        assert(x != 0);
        return power(mod - 2);
    }
    mint power(T b) const {
        mint res = 1, a = x;
        for (; b; b >>= 1, a *= a) {
            if (b & 1) res *= a;
        }
        return res;
    }
    mint &operator*=(const mint &rhs) {
        x = (V) x * rhs.x % mod;
        return *this;
    }
    mint &operator+=(const mint &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    mint &operator-=(const mint &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    mint &operator/=(const mint &rhs) { return *this *= rhs.inv(); }
    friend mint operator*(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res *= rhs;
        return res;
    }
    friend mint operator+(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res += rhs;
        return res;
    }
    friend mint operator-(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res -= rhs;
        return res;
    }
    friend mint operator/(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res /= rhs;
        return res;
    }
    friend bool operator==(const mint &lhs, const mint &rhs) {
        return lhs.x == rhs.x;
    }
    friend std::istream &operator>>(std::istream &is, mint &a) {
        T v;
        return is >> v, a = mint(v), is;
    }
    friend std::ostream &operator<<(std::ostream &os, const mint &a) {
        return os << a.val();
    }
    friend mint max(mint a, mint b) {
        return a.x > b.x ? a : b;
    }
    friend mint min(mint a, mint b) {
        return a.x < b.x ? a : b;
    }
};

// constexpr int MOD = 998244353;
constexpr int MOD = 1000000007;
using Z = mint<int32_t, MOD>;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int ymin, ymax, s, e, w;
    cin >> ymin >> ymax >> s >> e >> w;

    if (ymin > ymax || max(s, e) > ymax || min(s, e) < ymin) {
        cout << 0 << endl;
        return 0;
    }

    ymax -= ymin;
    s -= ymin;
    e -= ymin;

    Z dp[2][ymax + 1];
    memset(dp, 0, sizeof dp);

    int DP = 0;
    dp[DP][s] = 1;

    for (int i = 1; i <= w; i++) {
        DP ^= 1;
        for (int y = 0; y <= ymax; y++) dp[DP][y] = 0;
        for (int y = 0; y <= ymax; y++) {
            if (y - 1 >= 0)
                dp[DP][y] += dp[DP ^ 1][y - 1];
            if (y + 1 <= ymax)
                dp[DP][y] += dp[DP ^ 1][y + 1];
        }
    }

    cout << dp[DP][e] << endl;

    return 0;
}
