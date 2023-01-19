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

int n;
Z m;
map<int, Z> gmemo;
vector<vector<int>> factors(1e6 + 1);

void gen_factors(int x) {
    for (int i = 1; i <= x; i++) {
        if (x % i == 0) {
            for (int j = i; j <= x; j += i) {
                factors[j].push_back(i);
            }
        }
    }
}

Z g(int x, Z m) {
    if (gmemo.count(x))
        return gmemo[x];
    Z res = m.power(x);
    for (auto f: factors[x])
        if (f != x) res -= g(f, m);
    return gmemo[x] = res;
}

Z f(int x, Z m) {
    return g(x, m) / x;
}

Z necklaces(int n, Z m) {
    Z ans = 0;
    for (auto fact: factors[n])
        ans += f(fact, m);
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    gen_factors(4);
    cin >> n;
    // we can model the grid into a necklace of 4 beads and m colors
    if (n & 1)
        cout << necklaces(4, Z(2).power((n / 2) * (n / 2 + 1))) * 2 << endl;
    else
        cout << necklaces(4, Z(2).power((n / 2) * (n / 2))) << endl;
    return 0;
}
