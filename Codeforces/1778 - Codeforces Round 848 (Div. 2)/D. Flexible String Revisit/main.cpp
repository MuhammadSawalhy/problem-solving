// ﷽
// https://codeforces.com/contest/1778/problem/D

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

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
using Z = mint<int32_t, MOD>;

void solve() {
    int n;
    string first, second;
    cin >> n >> first >> second;
    int k = 0;
    for (int i = 0; i < n; i++) {
        k += first[i] != second[i];
    }

    if (n == 1) {
        cout << k << endl;
        return;
    }

    vector<Z> f(n + 1), a(n + 1), b(n + 1), c(n + 1), d(n + 1);
    c[n] = d[n] = 1;

    for (int i = n - 1; i > 0; i--) {
        c[i] = (1 + c[i + 1] * (n - i) / n) / (1 - d[i + 1] * (n - i) / n);
        d[i] = Z(i) / (n * (1 - d[i + 1] * (n - i) / n));
    }

    for (int i = 1; i <= n; i++) {
        f[i] = c[i] + d[i] * f[i - 1];
    }

    cout << f[k] << endl;
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
