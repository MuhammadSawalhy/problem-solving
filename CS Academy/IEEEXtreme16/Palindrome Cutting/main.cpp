// Date: 18-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

constexpr int mod = 998244353;

struct Z {
private:
    // assume -P <= x < 2P
    int norm(int x) const {
        if (x < 0)
            x += mod;
        if (x >= mod)
            x -= mod;
        return x;
    }

public:
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(ll x) : x(norm(x % mod)) {}
    int val() const { return x; }
    Z operator-() const { return Z(norm(mod - x)); }
    Z inv() const {
        assert(x != 0);
        return power(mod - 2);
    }
    Z power(Z b) const {
        Z res = 1;
        Z a = x;
        for (; b.x; a *= a, b.x >>= 1) {
            if (b.x % 2)
                res *= a;
        }
        return res;
    }
    Z &operator*=(const Z &rhs) {
        x = (ll) x * rhs.x % mod;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        ll v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};

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

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    // CAUTION: this is unsuccessful trial
    int n, m;
    cin >> n >> m;
    Z ans = choose(2 * n, n) / (n + 1);
    cout << ans << endl;

    return 0;
}
