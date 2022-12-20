// Date: 15-12-2022
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define debug(...)
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

vector<Z> fact(1, 1);
vector<Z> fact_inv(1, 1);

Z choose(int n, int k) {
    assert(n >= k && k >= 0);
    while ((int) fact.size() < n + 1) {
        fact.push_back(fact.back() * (int) fact.size());
        fact_inv.push_back(1 / fact.back());
    }
    return fact[n] * fact_inv[k] * fact_inv[n - k];
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    Z ans = 1, a = 1;
    int last = s[0] - '0', current;

    debug(s);
    for (int i = 1; i < n; i++) {
        current = s[i] - '0';
        if (last ^ current)
            a = 1, ans += a;
        else
            a *= 2, ans += a;
        last = current;
        debug(i, a);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
