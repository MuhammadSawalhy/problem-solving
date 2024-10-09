// ﷽
// https://cses.fi/problemset/task/2101

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
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

struct LCA {
    int n, LOG;
    vector<int> depth;
    vector<vector<int>> up, adj;

    LCA() = default;
    LCA(int n, int root = 0) : n(n), LOG(log2(n) + 1) {
        adj.resize(n), depth.resize(n);
        up.assign(n, vector<int>(LOG, root));
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int p) {
        for (auto v: adj[u]) {
            if (v == p) continue;
            up[v][0] = u;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }

    void build(int root = 0) {
        dfs(root, root);
        for (int k = 1; k < LOG; k++)
            for (int u = 0; u < n; u++)
                up[u][k] = up[up[u][k - 1]][k - 1];
    }

    int query(int u, int v) const {
        if (depth[u] < depth[v]) swap(u, v);
        for (int k = LOG - 1; k >= 0; k--) {
            if (depth[up[u][k]] >= depth[v]) {
                u = up[u][k];
            }
        }
        if (u == v) return u;
        for (int k = LOG - 1; k >= 0; k--) {
            if (up[u][k] != up[v][k]) {
                u = up[u][k];
                v = up[v][k];
            }
        }

        return up[u][0];
    }
};

struct DSU {
    vector<int> size, parent;
    int forests;

    DSU(int n) : forests(n) {
        size.assign(n, 1);
        parent.resize(n), iota(all(parent), 0);
    }

    bool connected(int x, int y) { return find(x) == find(y); }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool uni(int x, int y) { // merge x into y
        x = find(x), y = find(y);
        if (x == y) return false;
        forests--;
        parent[x] = y;
        size[y] += size[x];
        return true;
    }
};

const int N = 2e5 + 5;
int val[2 * N + 10];

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    DSU dsu(n * 2 - 1);

    vvi adj(n * 2 - 1);

    LCA lca(n * 2 - 1, n * 2 - 2);

    int nn = n;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        u = dsu.find(u), v = dsu.find(v);

        if (u == v) continue;

        // add the new edge

        debug(u, v, nn);
        dsu.uni(u, nn);
        dsu.uni(v, nn);

        lca.add_edge(u, nn);
        lca.add_edge(v, nn);

        val[nn] = i + 1;
        ++nn;
    }

    for (int i = 1; i < n * 2 - 1; i++) {
        if (!dsu.connected(i, i - 1)) {
            int u = dsu.find(i), v = dsu.find(i - 1);
            debug(i, i - 1, u, v);

            // add the new edge

            debug(u, v, nn);
            dsu.uni(u, nn);
            dsu.uni(v, nn);

            lca.add_edge(u, nn);
            lca.add_edge(v, nn);

            val[nn] = -1;
            ++nn;
        }
    }

    lca.build(n * 2 - 2);
    for (int i = 0; i < n * 2 - 1; i++) {
        debug(i, lca.adj[i]);
    }

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        int l = lca.query(u, v);

        debug(u, v, l);
        cout << val[l] << '\n';
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
