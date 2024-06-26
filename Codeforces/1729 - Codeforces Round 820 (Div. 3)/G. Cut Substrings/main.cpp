// ﷽
// https://codeforces.com/contest/1729/problem/G

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

vector<int> zfunction(string s) {
    int n = s.size();

    vector<int> z(n);
    for (int i = 1, l = 1, r = 1; i < n; i++) {
        if (i < r) z[i] = min(z[i - l], r - i);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) z[i]++;
        if (i + z[i] > r) r = i + z[i], l = i;
    }

    return z;
}

template<int32_t mod>
struct mint {
    using Z = mint;
    int32_t x;
    mint(int32_t x = 0) : x(norm(x)) {}
    mint(ll x) : x(norm(x % mod)) {}
    inline int32_t norm(int32_t x) const {
        return x >= mod ? x - mod
               : x < 0  ? x + mod
                        : x;
    }
    Z power(ll b) const {
        Z res = 1, a = x;
        for (; b; b >>= 1, a *= a)
            if (b & 1) res *= a;
        return res;
    }
    Z inv() const { return assert(x != 0), power(mod - 2); }
    Z operator-() const { return -x; }
    Z &operator*=(const Z &r) { return *this = (ll) x * r.x; }
    Z &operator+=(const Z &r) { return *this = x + r.x; }
    Z &operator-=(const Z &r) { return *this = x - r.x; }
    Z &operator/=(const Z &r) { return *this *= r.inv(); }
    friend Z operator*(const Z &l, const Z &r) { return Z(l) *= r; }
    friend Z operator+(const Z &l, const Z &r) { return Z(l) += r; }
    friend Z operator-(const Z &l, const Z &r) { return Z(l) -= r; }
    friend Z operator/(const Z &l, const Z &r) { return Z(l) /= r; }
    friend ostream &operator<<(ostream &os, const Z &a) { return os << a.x; }
    friend istream &operator>>(istream &is, Z &a) {
        ll y = 0;
        return is >> y, a = y, is;
    }
};

// constexpr int MOD = 998244353;
constexpr int MOD = 1000000007;
using Z = mint<MOD>;

struct info {
    int removed = 1e9;
    Z ways = 0;
    info operator+(int r) {
        return {removed + r, ways};
    }
    info operator+(const info &r) const {
        if (removed == r.removed) return {removed, ways + r.ways};
        if (removed > r.removed) return r;
        return *this;
    }
    friend ostream &operator<<(ostream &os, const info &a) {
        return os << '(' << a.removed << "," << a.ways << ')';
    }
};

void solve() {
    string s, t;
    cin >> s >> t;

    string ss = t + "#" + s;
    auto z = zfunction(ss);

    vector<int> pos;
    for (int i = sz(t) + 1; i < sz(ss); i++) {
        if (z[i] == sz(t)) {
            pos.push_back(i - sz(t) - 1);
        }
    }

    debug(s, pos);
    int n = s.size();

    info dp[2][n + 1];
    bool ok[2][n + 1];
    memset(ok, 0, sizeof ok);
    // dp[all removed?][removal or unremoved extend] = { removed , ways }

    dp[1][0] = {0, 1};
    ok[1][0] = 1;
    for (int i = 0; i < sz(pos); i++) {
        info newdp[2][n + 1];
        bool newok[2][n + 1];
        memset(newok, 0, sizeof newok);
        pos[i]++; // 1-based
        int e = pos[i] + sz(t) - 1;

        // all removed = true
        for (int j = 0; j <= n; j++) {
            if (!ok[1][j]) continue;
            if (j >= pos[i]) {
                // already removed
                newdp[1][j] = newdp[1][j] + dp[1][j];
                newok[1][j] = 1;
            } else {
                // remove
                newdp[1][e] = newdp[1][e] + (dp[1][j] + 1);
                newok[1][e] = 1;
                // keep
                newdp[0][e] = newdp[0][e] + dp[1][j];
                newok[0][e] = 1;
            }
        }

        // all removed = false
        for (int j = pos[i]; j <= e; j++) {
            if (!ok[0][j]) continue;
            // remove
            newdp[1][e] = newdp[1][e] + (dp[0][j] + 1);
            newok[1][e] = 1;
            // keep
            newdp[0][j] = newdp[0][j] + dp[0][j];
            newok[0][j] = 1;
        }

        memcpy(dp, newdp, sizeof newdp);
        memcpy(ok, newok, sizeof newok);
    }

    info ans;

    for (int j = 0; j <= n; j++) {
        if (ok[1][j]) {
            ans = ans + dp[1][j];
        }
    }

    cout << ans.removed << ' ' << ans.ways << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
