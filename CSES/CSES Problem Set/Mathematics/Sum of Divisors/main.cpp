// ﷽
#include <bits/stdc++.h>

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

using namespace std;

constexpr int MOD = 1000000007;// 998244353

template<int mod = MOD>
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
    mint(int32_t x = 0) : x(norm(x)) {}
    mint(ll x) : x(norm(x % mod)) {}
    int val() const { return x; }
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

using Z = mint<>;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    Z ans = 0;

    for (ll i = 1, r; i <= n; i++) {
        r = n / (n / i);
        // sum [x = i ... r] { floor(n / x) * x }
        // sum [x = i ... r] { floor(n / i) * x }
        // floor(n / i) * sum [x = i ... r] { x }
        ans += Z(n / i) * (Z(r + i) * (r - i + 1) / 2);
        i = r;
    }

    cout << ans << endl;

    return 0;
}
