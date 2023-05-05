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

// constexpr int MOD = 998244353;
constexpr int MOD = 1000000007;
using Z = mint<int32_t, MOD>;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    Z ans = 0;

    int n;
    cin >> n;

    int a[n];

    const int N = 1e6 + 6;
    vector<int> mp(N), primes;
    for (int i = 2; i < N; i++) {
        if (mp[i] == 0) mp[i] = i, primes.push_back(i);
        for (auto p : primes) {
            if (i * p >= N) break;
            mp[i * p] = p;
            if (mp[i] == p) break;
        }
    }

    map<int, int> overall;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        map<int, int> pf;
        int b = a[i];
        while (mp[b]) {
            pf[mp[b]]++;
            b /= mp[b];
        }
        for (auto [p, f] : pf) {
            overall[p] = max(overall[p], f);
        }
    }

    debug(overall);

    Z l = 1;
    for (auto [p, f] : overall) {
        while (f--)
            l *= p;
    }

    for (int i = 0; i < n; i++)
        ans += l / a[i];

    cout << ans;

    return 0;
}
