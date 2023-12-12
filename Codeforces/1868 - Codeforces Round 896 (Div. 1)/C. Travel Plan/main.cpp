// ﷽
// https://codeforces.com/contest/1868/problem/C

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
    mint power(V b) const {
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

const int M = 1e5 + 5, N = 1e18 + 1;
map<pair<int, int>, pair<pair<int, Z>, vector<Z>>> dp;

int n, m;

pair<int, Z> merge(const pair<int, Z> &A, const vector<Z> &a, const pair<int, Z> &B, const vector<Z> &b, vector<Z> &target) {
    target = vector<Z>(m + 1);
    Z AA = Z(m).power(A.first);
    Z BB = Z(m).power(B.first);
    Z extra = AA * BB;
    Z sum = A.second * BB * m + B.second * AA * m;
    for (int i = 1; i <= m; ++i) {
        target[i] = (i * a[i] - (i - 1) * a[i - 1]) * BB + (i * b[i] - (i - 1) * b[i - 1]) * AA + extra;
        sum += target[i] * i;
        sum += (i * a[i] * b[i] - (i - 1) * a[i - 1] * b[i - 1]) * i;
        target[i] += target[i - 1];
    }
    return {A.first + B.first + 1, sum};
}

void solve(int l, int r, int lastlevel, int lastlevelsize) {
    int lg = __lg(r - l + 1);
    if (dp.count({lg, lastlevel}))
        return;
    int mid = (l + r) >> 1;
    lastlevelsize /= 2;
    int left_lastlevel = min(lastlevel, lastlevelsize);
    int right_lastlevel = lastlevel - left_lastlevel;
    solve(mid + 1, r, right_lastlevel, lastlevelsize);
    solve(l, mid, left_lastlevel, lastlevelsize);
    auto &left = dp[{lg - 1, left_lastlevel}];
    auto &right = dp[{lg - 1, right_lastlevel}];
    auto sum = merge(left.first, left.second, right.first, right.second, dp[{lg, lastlevel}].second);
    dp[{lg, lastlevel}].first = sum;
}

void solve() {
    cin >> n >> m;
    int lg = 0;
    while ((1ll << lg) <= n) lg++;

    dp[{0, 0}].first = merge({0, 0}, vector<Z>(m + 1), {0, 0}, vector<Z>(m + 1), dp[{0, 0}].second);
    auto &one = dp[{0, 0}].first;
    auto &a = dp[{0, 0}].second;

    dp[{0, 1}].first = merge(one, a, {0, 0}, vector<Z>(m + 1), dp[{0, 1}].second);
    dp[{0, 2}].first = merge(one, a, one, a, dp[{0, 2}].second);
    debug(dp[{0, 0}]);
    debug(dp[{0, 1}]);
    debug(dp[{0, 2}]);

    if (n < (1ll << lg) - 1) {
        lg--;
    }

    int l = 1ll << (lg - 1), r = (1ll << lg) - 1;
    int lastlevel = n - (1ll << lg) + 1;
    int lastlevel_size = 1ll << lg;

    // debug(n, l, r);
    // debug(lastlevel, lastlevel_size);
    // return;

    solve(l, r, lastlevel, lastlevel_size);
    cout << dp[{__lg(r - l + 1), lastlevel}].first.second << '\n';

    debug(dp.size());
    dp.clear();
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
