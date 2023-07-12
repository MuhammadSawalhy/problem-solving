// Date: 16-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

constexpr int mod = 1000000007;

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

pair<int, int> max_power5(int n) {
    int p = 1, r = 0;
    while (p * 5 <= n)
        p *= 5, r++;
    return {p, r};
}

Z fives(int n) {
    Z res = 0;

    Z dp[100];
    Z base[100];

    Z p = 1;
    Z k = 0;
    base[0] = 0;
    for (int i = 1; i < 100; i++) {
        for (int j = 0; j < 5; j++) {
            dp[i] += dp[i - 1] + base[i] * p;
            base[i] += base[i - 1];
        }
        base[i] += 1;
        p *= 5;
    }

    Z b = 0;
    while (n > -1) {
        auto [p, r] = max_power5(n);
        debug(n, p, r);
        res += b * p + dp[r];
        b += base[r];
        n -= p;
    }
    debug(res);

    return res;
}

void solve() {
    int a, b;
    cin >> a >> b;

    Z ans = fives(b) - fives(a - 1);

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
