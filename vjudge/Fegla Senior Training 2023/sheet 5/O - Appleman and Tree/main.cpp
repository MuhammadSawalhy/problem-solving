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

constexpr int MOD = 1000000007;// 998244353
using Z = mint<int32_t, MOD>;

const int N = 1e5;
vector<int> adj[N];
bool color[N];
Z dp[N][2];

Z solve(int i, int p, bool black) {
    bool leaf = true;
    Z &ans = dp[i][black];
    if (ans.x != -1)
        return ans;

    if (!black && color[i])
        return ans = 0;

    Z white = 1;
    for (auto j : adj[i]) {
        if (j == p) continue;
        leaf = false;
        white *= (solve(j, i, false) + solve(j, i, true));
    }

    if (leaf)
        return ans = color[i] == black;

    if (!black || color[i])
        return ans = white;

    ans = 0;

    debug(i, white);
    for (auto j : adj[i]) {
        if (j == p) continue;
        leaf = false;
        ans += white / (solve(j, i, false) + solve(j, i, true)) * solve(j, i, true);
    }

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1, p; i < n; i++) {
        cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    for (int i = 0; i < n; i++)
        cin >> color[i];

    memset(dp, -1, sizeof dp);

    cout << solve(0, 0, true);
    return 0;

    for (int i = 0; i < n; i++)
        if (color[i]) {
            cout << solve(i, i, true);
            break;
        }

    return 0;
}
