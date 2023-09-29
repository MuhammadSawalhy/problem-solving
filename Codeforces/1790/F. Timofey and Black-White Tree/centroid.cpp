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

#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

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

struct LCA {
    int n, LOG;
    vector<int> depth;
    vector<vector<int>> parent, adj;

    LCA() : n(0), LOG(-1e9) {}

    LCA(const vector<vector<int>> &adj, int root = 0) : adj(adj), n(adj.size()), LOG(log2(n) + 1) {
        depth.resize(n);
        parent = vector<vector<int>>(n, vector<int>(LOG, root));
        preprocess(root);
    }

    void dfs(int u, int p) {
        for (auto v: adj[u]) {
            if (v == p) continue;
            parent[v][0] = u;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }

    void preprocess(int root) {
        dfs(root, root);
        for (int k = 1; k < LOG; k++)
            for (int u = 0; u < n; u++)
                parent[u][k] = parent[parent[u][k - 1]][k - 1];
    }

    int query(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int k = LOG - 1; k >= 0; k--) {
            if (depth[parent[u][k]] >= depth[v]) {
                u = parent[u][k];
            }
        }
        if (u == v) return u;
        for (int k = LOG - 1; k >= 0; k--) {
            if (parent[u][k] != parent[v][k]) {
                u = parent[u][k];
                v = parent[v][k];
            }
        }
        return parent[u][0];
    }
};

void solve() {
    int n, c0;
    cin >> n >> c0;

    int c[n];
    Centroids cen(n);

    c[0] = c0 - 1;
    for (int i = 1; i < n; i++) {
        cin >> c[i], c[i]--;
    }

    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        cen.add_edge(u, v);
    }

    LCA lca(cen.edges);
    cen.build();

    auto dist = [&](int u, int v) {
        int lc = lca.query(u, v);
        return lca.depth[u] + lca.depth[v] - 2 * lca.depth[lc];
    };

    int ans = 1e9;
    vector<int> nearest(n, 1e9);
    for (int i = 0; i < n; i++) {
        for (int j = c[i]; j != -1; j = cen.par[j]) {
            int d = dist(c[i], j);
            ans = min(ans, nearest[j] + d);
            nearest[j] = min(nearest[j], d);
        }
        if (i > 0) cout << ans << ' ';
    }
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
