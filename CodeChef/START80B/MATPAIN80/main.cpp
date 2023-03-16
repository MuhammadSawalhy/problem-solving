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

constexpr int MOD = 1000000007;// 998244353
using Z = mint<ll, MOD>;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    Z ans = Z(n) * m * (Z(n) * m + 1) / 2;

    map<int, Z> row, col;
    for (int i = 0, q, x, v; i < k; i++) {
        cin >> q >> x >> v;
        if (q == 0) {
            if (row.count(x))
                row[x] *= v;
            else
                row[x] = v;
        } else{
            if (col.count(x))
                col[x] *= v;
            else
                col[x] = v;
        }
    }

    Z sum = 0;
    Z SUM = 0;
    Z s = 0;

    for (auto [x, v] : col) {
        // add_col(ans, x, v)
        s += v;
        sum += x;
        SUM += Z(x) * v;
        ans += ((Z(n) * (n - 1) / 2) * m + Z(x) * n) * (v - 1);
    }

    for (auto [x, v] : row) {
        // add_row(ans, x, v);
        Z a = Z(x - 1) * m;
        Z b = Z(x) * m;
        ans += (b * (b + 1) - a * (a + 1)) / 2 * (v - 1);

        Z y = Z(x - 1) * m * col.size();
        ans += y + sum;
        ans += (Z(x - 1) * m * s + SUM) * v;

        ans -= Z(x - 1) * m * s + SUM;
        ans -= (y + sum) * v;
    }

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

