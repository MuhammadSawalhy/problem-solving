// Date: 16-12-2022
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define debug(...)
#ifdef LOCAL
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    bool ok = true;
    vector<vector<int>> cons(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        bool diff = false;
        for (int j = i; j <= n; j++) {
            cin >> cons[i][j];
            if (cons[i][j] == 1 && diff)
                ok = false;
            diff |= cons[i][j] == 2;
        }
    }

    if (!ok) {
        cout << 0 << endl;
        return 0;
    }


    Z dp[n + 1][n + 1][2];
    dp[0][1][0] = (cons[1][1] != 2) * 2;
    for (int i = 1; i <= n; i++) {
        if (cons[i][i] == 2) {
            dp[n][n][0] = 0;
            dp[n][n][1] = 0;
            break;
        }
        dp[i][i][0] = dp[i - 1][i][0];
        dp[i][i][1] = dp[i - 1][i][1];
        for (int j = i + 1; j <= n; j++) {
            if (cons[i][j] == 0 || cons[i][j] == 2) {
                dp[i][j][1] = dp[i][j - 1][0] + dp[i][j - 1][1] * 2;
                dp[i][j][0] = 0;
            }
            if (cons[i][j] == 0 || cons[i][j] == 1) {
                dp[i][j][0] = dp[i][j - 1][0];
            }
        }
    }

    cout << max(dp[n][n][0].x, dp[n][n][1].x) << endl;

    return 0;
}
