// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

template<typename T = void>
struct OtherType {
    typedef ll type;
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
    mint(T x = 0) : x(norm(x)) {}
    T val() const { return x; }
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

void solve() {
    int n, k;
    cin >> n >> k;

    // dp[2][val][prev]
    Z dp[2][n + 1][n + 1];

    int DP = 0;
    for (int j = 1; j <= n; j++) {
        for (int r = 1; r <= n; r++) {
            dp[DP][j][r] = abs(j - r) <= k;
            dp[DP][j][r] += dp[DP][j][r - 1];
        }
    }

    for (int i = 3; i <= n; i++) {
        DP ^= 1;
        for (int j = 1; j <= n; j++) {
            for (int r = 1; r <= n; r++) {
                if (abs(j - r) > k) {
                    dp[DP][j][r] = 0;
                    continue;
                }
                int s = max(1LL, max(j, r) - k);
                int e = min(n, min(j, r) + k);
                dp[DP][j][r] = dp[DP ^ 1][r][e] - dp[DP ^ 1][r][s - 1];
            }

            for (int r = 1; r <= n; r++)
                dp[DP][j][r] += dp[DP][j][r - 1];
        }
    }

    Z ans = 0;
    for (int i = 1; i <= n; i++)
        ans += dp[DP][i][n];
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
