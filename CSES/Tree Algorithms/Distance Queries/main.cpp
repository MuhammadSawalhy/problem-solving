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

#define ll     long long
#define all(v) v.begin(), v.end()

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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, q;
    scanf("%d%d", &n, &q);
    vector<vector<int>> adj(n);
    vector<int> dist(n);

    for (int i = 0, a, b; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    function<void(int, int)> dfs = [&](int i, int p) {
        for (auto j: adj[i]) {
            if (j == p) continue;
            dist[j] = dist[i] + 1;
            dfs(j, i);
        }
    };

    dfs(0, 0);
    LCA lca(adj);
    int a, b;

    while (q--) {
        scanf("%d%d", &a, &b);
        a--, b--;

        printf("%d\n", dist[a] + dist[b] - 2 * dist[lca.query(a, b)]);
    }

    return 0;
}
