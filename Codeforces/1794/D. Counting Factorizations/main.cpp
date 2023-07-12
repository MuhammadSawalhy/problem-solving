// ﷽
#include <algorithm>
#include <array>
#include <assert.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string.h>
#include <utility>
#include <vector>

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

template<int mod>
struct mint {
private:
    // assume -P <= x < 2P, (it's faster)
    int norm(int x) const {
        if (x < 0)
            x += mod;
        if (x >= mod)
            x -= mod;
        return x;
    }

public:
    int x;
    int val() const { return x; }
    mint(int32_t x = 0) : x(norm(x)) {}
    mint(ll x) : x(norm(x % mod)) {}
    mint operator-() const { return mint(norm(mod - x)); }
    mint inv() const {
        assert(x != 0);
        return power(mod - 2);
    }
    mint power(ll b) const {
        mint res = 1, a = x;
        while (b) {
            if (b & 1) res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }
    mint &operator*=(const mint &rhs) {
        x = (ll) x * rhs.x % mod;
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
    friend std::istream &operator>>(std::istream &is, mint &a) {
        ll v;
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

constexpr int MOD = 998244353;// 1000000007
using Z = mint<MOD>;

vector<Z> fact = {1};
vector<Z> fact_inv = {1};

void build_fact(int n = 1e6) {
    while ((int) fact.size() < n + 1)
        fact.push_back(fact.back() * (int) fact.size());
    fact_inv.resize(fact.size());
    fact_inv.back() = fact.back().inv();
    for (int j = fact_inv.size() - 2; fact_inv[j].x == 0; j--)
        fact_inv[j] = fact_inv[j + 1] * (j + 1);
}

Z choose(int n, int r) {
    if (r > n || r < 0) return 0;
    if ((int) fact.size() < n + 1) build_fact(n);
    return fact[n] * fact_inv[r] * fact_inv[n - r];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    build_fact();

    int n;
    cin >> n;
    int a[n * 2];
    Z ans = 0;
    set<int> primes;

    vector<bool> is_prime(1e6 + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= 1e6; i++) {
        if (!is_prime[i]) continue;
        for (int j = i * i; j <= 1e6; j += i)
            is_prime[j] = false;
    }

    map<int, int> fr;
    for (int i = 0; i < n * 2; i++) {
        cin >> a[i], fr[a[i]]++;
        if (is_prime[a[i]])
            primes.insert(a[i]);
    }

    if (primes.size() < n) {
        cout << 0 << endl;
        return 0;
    }

    ans = fact[n];

    for (auto [b, f]: fr) {
        if (!is_prime[b])
            ans *= fact_inv[f];
    }

    int m = primes.size();
    Z dp[m + 1][n + 1];
    memset(dp, 0, sizeof dp);

    int j = 1;
    dp[0][0] = 1;
    for (auto p : primes) {
        int f = fr[p];
        dp[j][0] = dp[j - 1][0] * fact_inv[f];
        for (int i = 1; i <= n; i++) {
            dp[j][i] = dp[j - 1][i] * fact_inv[f] + dp[j - 1][i - 1] * fact_inv[f - 1];
        }
        j++;
    }

    cout << ans * dp[m][n] << endl;

    return 0;
}
