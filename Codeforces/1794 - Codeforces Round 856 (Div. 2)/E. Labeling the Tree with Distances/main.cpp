// ﷽
// https://codeforces.com/contest/1794/problem/E#

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

struct HashValue;
constexpr int HASH_ITER = 1;
mt19937 rng(random_device{}());
const ll M = (1LL << 61) - 1;
vector<HashValue> B;

struct HashValue {
    long long val[HASH_ITER]{};
    HashValue(long long v = 0) {
        for (int i = 0; i < HASH_ITER; i++) val[i] = v;
    }
    HashValue &operator-=(const HashValue &a) {
        for (int i = 0; i < HASH_ITER; i++) val[i] = (val[i] - a.val[i] + M) % M;
        return *this;
    }
    HashValue &operator+=(const HashValue &a) {
        for (int i = 0; i < HASH_ITER; i++) val[i] = (val[i] + a.val[i]) % M;
        return *this;
    }
    HashValue &operator*=(const HashValue &a) {
        for (int i = 0; i < HASH_ITER; i++) val[i] = ((__int128) val[i] * a.val[i]) % M;
        return *this;
    }
    HashValue operator+(const HashValue &a) { return HashValue(*this) += a; }
    HashValue operator-(const HashValue &a) { return HashValue(*this) -= a; }
    HashValue operator*(const HashValue &a) { return HashValue(*this) *= a; }
    bool operator<(const HashValue &a) const {
        for (int i = 0; i < HASH_ITER; i++)
            if (val[i] != a.val[i]) return val[i] < a.val[i];
        return false;
    }
    bool operator==(const HashValue &a) const {
        for (int i = 0; i < HASH_ITER; i++)
            if (val[i] != a.val[i]) return false;
        return true;
    }
};

void setB(int n) {
    if (B.size() == 0) {
        HashValue v;
        B.push_back(v + 1);
        for (int i = 0; i < HASH_ITER; i++)
            v.val[i] = uniform_int_distribution<ll>(0, M - 1)(rng);
        B.push_back(v);
    }
    while (B.size() <= n) B.push_back(B.back() * B[1]);
}

struct Hash {
    vector<HashValue> p_hash;

    Hash(const string &s) : p_hash(s.size() + 1) {
        setB(s.size());
        for (int i = 0; i < s.size(); i++)
            p_hash[i + 1] = p_hash[i] * B[1] + s[i];
    }

    auto get_hash(int start, int end) {
        return p_hash[end + 1] - p_hash[start] * B[end - start + 1];
    }
};


const int N = 2e5 + 5;
vector<int> adj[N], ans;
set<HashValue> hashes;
HashValue val[N];
int n, a[N], d[N];

void dfs(int u, int p) {
    val[u] = 1;
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        val[u] += val[v] * B[1];
    }
}

void calc(int u, int p, HashValue up) {
    val[u] = val[u] + up;
    if (hashes.count(val[u])) ans.push_back(u);
    for (auto v: adj[u]) {
        if (v == p) continue;
        calc(v, u, (val[u] - val[v] * B[1]) * B[1]);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) cin >> a[i], d[a[i]]++;
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    HashValue hash;

    for (int i = 0; i < n; i++)
        hash += B[i] * d[i];

    for (int i = 0; i < n; i++) {
        hashes.insert(hash + B[i]);
    }

    dfs(0, -1);
    calc(0, -1, 0);

    cout << ans.size() << endl;
    sort(all(ans));
    for (auto i: ans) {
        cout << i + 1 << " ";
    }
    cout << endl;

    ans.clear();
    hashes.clear();
    for (int i = 0; i < n; i++) {
        adj[i].clear();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    setB(N);

    // int t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
