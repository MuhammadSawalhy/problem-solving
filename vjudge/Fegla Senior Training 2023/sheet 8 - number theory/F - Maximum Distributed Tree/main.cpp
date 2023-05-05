// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define int    long long
#define ll     long long
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
        if (x < 0) x += mod;
        if (x >= mod) x -= mod;
        return x;
    }

public:
    T x;
    T val() const { return x; }
    mint(V x = 0) : x(norm(x % mod)) {}
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
        return is >> v, a = mint(v), is;
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

// constexpr int MOD = 998244353;
constexpr int MOD = 1000000007;
using Z = mint<int32_t, MOD>;

const int N = 1e5;
int cnt[N];
vector<int> adj[N];
vector<ll> edge_values;

void calc_cnt(int i, int p) {
    cnt[i] = 1;
    for (auto j: adj[i]) {
        if (j == p) continue;
        calc_cnt(j, i);
        cnt[i] += cnt[j];
    }
}

void calc_edge_values(int i, int p, int topcnt) {
    if (i != p) { // root
        // we have and edge between i and p
        edge_values.push_back(1LL * topcnt * cnt[i]);
    }
    for (auto j: adj[i]) {
        if (j == p) continue;
        calc_edge_values(j, i, topcnt + cnt[i] - cnt[j]);
    }
}

void solve() {
    int n;
    cin >> n;

    edge_values.clear();
    for (int i = 0; i < n; i++) {
        adj[i].clear();
        cnt[i] = 0;
    }

    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    calc_cnt(0, 0);
    calc_edge_values(0, 0, 0);

    int m;
    cin >> m;

    int p[max(m, n - 1)];
    for (int i = 0; i < m; i++)
        cin >> p[i];

    while (m < n - 1)
        p[m++] = 1;

    assert(edge_values.size() == n - 1);
    sort(all(edge_values));
    sort(p, p + m);

    Z pp[m];
    for (int i = 0; i < m; i++)
        pp[i] = p[i];

    while (m > n - 1)
        pp[m-- - 2] *= pp[m - 1];

    Z ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += pp[i] * edge_values[i];
    }

    cout << ans << '\n';
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
