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

#define ll long long
#define int long long
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

const int MAX = 1505;
Z dp[MAX][MAX][2][2];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    bool box[n];

    for (int i = 0; i < n; i++)
        cin >> box[i];

    bool same = true;
    for (int i = 1; i < n; i++)
        same &= box[i] == box[i - 1];

    if (same) {
        cout << (k == 0) << endl;
        return 0;
    }

    dp[0][0][0][box[0]] = 1;

    for (int i = 1; i < n; i++) {
        for (int moves = 0; moves <= k; moves++) {
            for (int prev = 0; prev < 2; prev++) {
                for (int next = 0; next < 2; next++) {
                    // ?(0|0, 0|1, 1|0, 1|1)?
                    // next changed?
                    // prev changed?

                    // both should change together (moves + 1)
                    if (next != box[i]) {
                        if (prev != next)
                            dp[i][moves + 1][prev][next] +=
                                    dp[i - 1][moves][0][next] +
                                    dp[i - 1][moves][1][next];
                    } else
                        // or stay unchanged together (moves)
                        dp[i][moves][prev][next] +=
                                dp[i - 1][moves][0][prev] +
                                dp[i - 1][moves][1][prev];

                    debug(i, moves, prev, next);
                    debug(dp[i][moves][prev][next]);
                }
            }
        }
    }

    Z ans = 0;
    for (int moves = k & 1; moves <= k; moves += 2)
        for (int prev = 0; prev < 2; prev++)
            for (int next = 0; next < 2; next++)
                ans += dp[n - 1][moves][prev][next];
    cout << ans << endl;

    return 0;
}
