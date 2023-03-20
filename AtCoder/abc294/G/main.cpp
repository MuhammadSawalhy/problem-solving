#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e5+5;
const int LOGN = 20;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#endif

int N, Q;
int par[MAXN][LOGN], dep[MAXN], dist[MAXN];
vector<pair<int, int>> adj[MAXN];

void dfs(int u, int p) {
    for (auto [v, w] : adj[u]) {
        if (v == p) continue;
        par[v][0] = u;
        dep[v] = dep[u] + 1;
        dist[v] = dist[u] + w;
        dfs(v, u);
    }
}

void preprocess() {
    dfs(1, 0);
    for (int k = 1; k < LOGN; k++) {
        for (int u = 1; u <= N; u++) {
            int p = par[u][k-1];
            par[u][k] = par[p][k-1];
        }
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int k = LOGN-1; k >= 0; k--) {
        if (dep[par[u][k]] >= dep[v]) {
            u = par[u][k];
        }
    }
    if (u == v) return u;
    for (int k = LOGN-1; k >= 0; k--) {
        if (par[u][k] != par[v][k]) {
            u = par[u][k];
            v = par[v][k];
        }
    }
    return par[u][0];
}

int distance(int u, int v) {
    int p = lca(u, v);
    return dist[u] + dist[v] - 2 * dist[p];
}

void update(array<int, 3> &edge, int w) {
    auto [a, b, ww] = edge;
    if (par[a][0] == b) swap(a, b);
    dist[b] += w - ww;
    edge[2] = w;
}

int32_t main() {
    cin >> N;
    array<int, 3> edges[N + 1];
    for (int i = 1; i < N; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges[i] = {u, v, w};
    }
    preprocess();
    cin >> Q;
    while (Q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int e, w;
            cin >> e >> w;
            debug(edges[e]);
            update(edges[e], w);
        } else {
            int u, v;
            cin >> u >> v;
            cout << distance(u, v) << endl;
        }
    }
    return 0;
}

