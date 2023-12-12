// ﷽
// https://codeforces.com/contest/1516/problem/E

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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

template<typename T = void> // default
struct BiggerType {
    typedef ll type;
};

template<> // for long long
struct BiggerType<ll> {
    typedef __int128 type;
};

template<typename T, T mod, typename V = typename BiggerType<T>::type>
struct mint {
private:
    inline T norm(T x) const {
        if (x < 0) x += mod;
        if (x >= mod) x -= mod;
        return x;
    }

public:
    T x;
    mint(T x = 0) : x(norm(x)) {}
    mint(V x) : x(norm(x % mod)) {}
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
        return os << a.x;
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

Z ncr(int n, int r) {
    Z a = 1, b = 1;
    for (int x = n; x >= n - r + 1; x--) a *= x;
    for (int x = 1; x <= r; x++) b *= x;
    return a / b;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    Z dp[2 * k + 1][2 * k + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    dp[1][0][0] = 1;

    for (int i = 2; i <= 2 * k; i++) {
        dp[i][0][0] = 1;
        for (int a = 0; a <= i; a++) {
            for (int j = 1; j <= k; j++) {
                dp[i][a][j] = dp[i - 1][a][j];
                if (a > 0) dp[i][a][j] += (a - 1) * dp[i - 1][a - 1][j - 1];
                if (a > 1) dp[i][a][j] += (i - 1 - (a - 2)) * dp[i - 1][a - 2][j - 1];
            }
        }
    }

    Z dp2[k + 1];
    dp2[0] = 1;

    for (int j = 1; j <= k; j++) {
        dp2[j] = 0;
        for (int i = j + 1; i <= 2 * j; i++) {
            dp2[j] += dp[i][i][j] * ncr(n, i);
        }
    }

    for (int i = 1; i <= k; i++) {
        if (i > 1) dp2[i] += dp2[i - 2];
        cout << dp2[i] << ' ';
    }

    return 0;
}
