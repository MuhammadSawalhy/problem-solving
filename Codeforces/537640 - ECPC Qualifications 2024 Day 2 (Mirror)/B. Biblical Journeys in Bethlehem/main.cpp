// ﷽
// https://codeforces.com/group/Rilx5irOux/contest/537640/problem/B

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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

const int N = 4e4 + 4;
char ch[N];
vector<int> adj[N];

struct Centroids {
    vector<vector<int>> edges;
    vector<bool> removed;
    vector<int> par;
    vector<int> sz;
    int n;

    Centroids(int n) : n(n) {
        edges.resize(n), removed.resize(n);
        sz.resize(n), par.assign(n, -1);
    }

    void add_edge(int a, int b) {
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    void find_size(int v, int p = -1) {
        sz[v] = 1;
        for (int x: edges[v]) {
            if (x == p || removed[x]) continue;
            find_size(x, v), sz[v] += sz[x];
        }
    }

    int find_centroid(int v, int p, int n) {
        for (int x: edges[v]) {
            if (x == p || removed[x]) continue;
            if (sz[x] > n / 2) return find_centroid(x, v, n);
        }
        return v;
    }

    void build(int v = 0, int p = -1) {
        find_size(v);
        int c = find_centroid(v, -1, sz[v]);
        removed[c] = true, par[c] = p;
        for (int x: edges[c])
            if (!removed[x]) build(x, c);
    }
};

typedef valarray<ll> val;
constexpr int hashes = 2;
vector<val> B;
const val M = {
        1000000007,
        1444444447,
        // 998244353,
};

void setB(int n) {
    if (B.size() == 0) {
        mt19937 rng(random_device{}());
        B.assign(2, val(1, hashes));
        for (int i = 0; i < hashes; i++)
            B.back()[i] = uniform_int_distribution<ll>(1, M[i] - 1)(rng);
    }
    while ((int) B.size() <= n) B.push_back(B.back() * B[1] % M);
}

// struct Hash {
//     vector<val> h;
//
//     Hash(const string &s) : h(s.size() + 1) {
//         setB(s.size()), h[0] = val(hashes);
//         for (int i = 0; i < (int) s.size(); i++)
//             h[i + 1] = (h[i] * B[1] + s[i]) % M;
//     }
//
//     auto get(int l, int r) {
//         array<ll, hashes> arr;
//         val ans = (h[r + 1] - h[l] * B[r - l + 1] % M + M) % M;
//         for (int i = 0; i < hashes; i++) arr[i] = ans[i];
//         return arr;
//     }
// };

void solve() {
    int n;
    cin >> n;
    Centroids cen(n);
    for (int i = 0; i < n; i++) cin >> ch[i];
    for (int i = 0; i < n - 1; i++) {
        int u,v ;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cen.add_edge(u, v);
    }

    cen.build();
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    setB(N);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
