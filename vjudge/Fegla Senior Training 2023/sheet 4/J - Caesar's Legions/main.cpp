// ﷽
#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

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

constexpr int MOD = 1e8;// 998244353
using Z = mint<int32_t, MOD>;

const int N = 202, K = 11;
Z dp[N][N][K][K];
bool vis[N][N][K][K];
int n1, n2, k1, k2;

Z solve(int i, int j, int k, int l) {
    if (i > n1 || j > n2 || k > k1 || l > k2) return 0;
    if (i == n1 && j == n2) return 1;
    Z &r = dp[i][j][k][l];
    if (vis[i][j][k][l]) return r;
    vis[i][j][k][l] = true;

    r = 0;
    r += solve(i + 1, j, k + 1, 0);
    r += solve(i, j + 1, 0, l + 1);

    return r;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n1 >> n2 >> k1 >> k2;

    cout << solve(0, 0, 0, 0);

    return 0;
}
