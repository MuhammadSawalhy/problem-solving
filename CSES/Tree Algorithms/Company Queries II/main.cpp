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
#define int    long long
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
            debug(u + 1, v + 1);
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

    int find_parent(int x, int k) {
        debug(depth[x]);
        if (k > depth[x]) return -1;
        for (int i = 0; i < LOG; i++, k >>= 1) {
            if (k & 1)
                x = parent[x][i];
        }
        return x + 1;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n);

    for (int i = 1, e; i < n; i++) {
        cin >> e, e--;
        adj[e].push_back(i);
    }

    debug(adj);
    LCA lca(adj);

    while (q--) {
        int x, y;
        cin >> x >> y, x--, y--;
        cout << lca.query(x, y) + 1 << '\n';
    }

    return 0;
}
