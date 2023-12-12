// ﷽
// https://cses.fi/problemset/task/1075/

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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    if (n == 2) {
        cout << 0 << endl;
        return 0;
    }

    Z dp[n + 1][n + 1][3];
    dp[1][0][0] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // ----- no left or right
            dp[i + 1][j][0] += dp[i][j][0] * (i + 1 - j - 2);
            if (j > 0) dp[i + 1][j - 1][0] += dp[i][j][0] * (j);
            dp[i + 1][j + 1][1] += dp[i][j][0];
            dp[i + 1][j + 1][2] += dp[i][j][0];

            // ----- left is invalid
            dp[i + 1][j][0] += dp[i][j][1] * (i + 1 - j - 1);
            if (j > 0) dp[i + 1][j - 1][0] += dp[i][j][1] * (j - 1);
            dp[i + 1][j][2] += dp[i][j][1];
            dp[i + 1][j + 1][1] += dp[i][j][1];

            // ----- right is invalid
            dp[i + 1][j][0] += dp[i][j][2] * (i + 1 - j - 1);
            if (j > 0) dp[i + 1][j - 1][0] += dp[i][j][2] * (j - 1);
            dp[i + 1][j][1] += dp[i][j][2];
            dp[i + 1][j + 1][2] += dp[i][j][2];
        }
    }

    cout << dp[n][0][0] << endl;

    return 0;
}
