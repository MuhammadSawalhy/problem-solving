// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
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
        if (x < 0)
            x = x % mod + mod;
        if (x >= mod)
            x %= mod;
        return x;
    }

public:
    T x;
    T val() const { return x; }
    mint(T x = 0) : x(norm(x)) {}
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
        is >> v;
        a = mint(v);
        return is;
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

constexpr int MOD = 998244353;// 998244353
using Z = mint<int32_t, MOD>;

Z dp[2][2][201];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int DP = 0;

    if (a[0] == -1)
        for (int j = 1; j <= 200; j++) dp[DP][0][j] = 1;
    else
        dp[DP][0][a[0]] = 1;

    for (int i = 1; i < n; i++) {
        for (int k = 0; k < 2; k++)
            for (int j = 1; j <= 200; j++)
                dp[DP][k][j] += dp[DP][k][j - 1], dp[DP ^ 1][k][j] = 0;
        DP ^= 1;

        if (a[i] != -1) {
            dp[DP][0][a[i]] = dp[DP ^ 1][0][a[i] - 1] + dp[DP ^ 1][1][a[i] - 1];
            dp[DP][1][a[i]] = dp[DP ^ 1][0][a[i]] - dp[DP ^ 1][0][a[i] - 1];
            dp[DP][1][a[i]] += dp[DP ^ 1][1][200] - dp[DP ^ 1][1][a[i] - 1];
            continue;
        }

        for (int j = 1; j <= 200; j++) {
            dp[DP][0][j] = dp[DP ^ 1][0][j - 1] + dp[DP ^ 1][1][j - 1];
            dp[DP][1][j] = dp[DP ^ 1][0][j] - dp[DP ^ 1][0][j - 1];
            dp[DP][1][j] += dp[DP ^ 1][1][200] - dp[DP ^ 1][1][j - 1];
        }
    }

    for (int j = 1; j <= 200; j++) dp[DP][1][j] += dp[DP][1][j - 1];
    cout << dp[DP][1][200];

    return 0;
}
