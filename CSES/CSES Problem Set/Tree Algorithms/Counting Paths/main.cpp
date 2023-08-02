// ﷽
// https://cses.fi/problemset/task/1136
// CSES -> CSES Problem Set -> Counting Paths

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

char in[1 << 24];
struct scanner {
    char const *o;
    scanner() : o(in) { load(); }
    void load() { in[fread(in, 1, sizeof(in) - 4, stdin)] = 0; }
    unsigned readInt() {
        unsigned u = 0;
        while (*o && *o <= 32) ++o;
        while (*o >= '0' && *o <= '9')
            u = u * 10 + (*o++ - '0');
        return u;
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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    scanner sc;

    int n = sc.readInt(), m = sc.readInt();

    vector<vector<int>> adj(n);
    for (int i = 0, a, b; i < n - 1; i++) {
        a = sc.readInt(), b = sc.readInt(), a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    LCA lca(adj);
    vector<int> val(n);

    for (int i = 0, a, b; i < m; i++) {
        a = sc.readInt(), b = sc.readInt(), a--, b--;
        if (a == b) {
            val[a] += 1;
            int p = lca.parent[a][0];
            if (p != a) val[p] -= 1;
            continue;
        }

        int l = lca.query(a, b);
        int p = lca.parent[l][0];
        val[a] += 1;
        val[b] += 1;
        val[l] -= 1;
        if (p != l) {
            val[p] -= 1;
        }
    }

    vector<int> ans(n);
    function<void(int, int)> dfs = [&](int i, int p) {
        ans[i] += val[i];
        for (auto j: adj[i]) {
            if (j == p) continue;
            dfs(j, i);
            ans[i] += ans[j];
        }
    };

    dfs(0, 0);

    for (auto i: ans) cout << i << ' ';
    return 0;
}
