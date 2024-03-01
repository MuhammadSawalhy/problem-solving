// ﷽
// https://codeforces.com/contest/1914/problem/G2

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
    mint power(long long b) const {
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

struct SCC {
    int N, ID = 0, COMP = 0;
    vector<vector<int>> adj;
    vector<int> id, comp, st;

    SCC(const vector<vector<int>> &adj) : adj(adj), N(adj.size()) {
        id.resize(N), comp = vector<int>(N, -1);
        go();
    }

    void go() {
        for (int i = 0; i < N; i++)
            if (!id[i]) dfs(i);
    }

    int dfs(int i) {
        int low = id[i] = ++ID;
        st.push_back(i);
        for (int j: adj[i])
            if (comp[j] == -1)
                // id[j] != 0 -> in stack, don't dfs
                low = min(low, id[j] ?: dfs(j));
        if (low == id[i]) {
            COMP++;
            for (int j = -1; j != i;)
                comp[j = st.back()] = COMP, st.pop_back();
        }
        return low;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    vector<int> f(n, -1);
    vector<int> s(n, -1);
    vector<int> right(n);
    vector<int> len[2 * n];
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        a[i]--;
        if (f[a[i]] == -1) f[a[i]] = i;
        else s[a[i]] = i, len[s[a[i]] - f[a[i]]].push_back(a[i]), right[a[i]] = i;
    }

    vector<vector<int>> adj(n);
    for (int i = 2 * n - 1; ~i; i--) {
        if (s[a[i]] == i) continue;
        int ff = f[a[i]];
        int ss = s[a[i]];
        assert(ff == i);
        for (int j = ff + 1; j < ss;) {
            adj[a[i]].push_back(a[j]);
            maxit(right[a[i]], right[a[j]]);
            j = right[a[j]] + 1;
        }
    }

    SCC scc(adj);
    map<int, int> fr;
    map<int, int> degin;
    for (int i = 0; i < n; i++) {
        fr[scc.comp[i]]++;
        for (auto j: adj[i])
            if (scc.comp[i] != scc.comp[j])
                degin[scc.comp[j]]++;
    }

    Z ans = 1;
    int cnt = 0;
    for (auto [x, f]: fr) {
        if (degin[x] == 0) {
            ans *= f;
            cnt++;
        }
    }

    for (int i = 0; i < n; i++)
        debug(i, adj[i]);
    ans *= Z(2).power(cnt);
    cout << cnt << ' ' << ans << endl;
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
