// ﷽
// https://codeforces.com/contest/321/problem/C

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

    int build(int v = 0, int p = -1) {
        find_size(v);
        int c = find_centroid(v, -1, sz[v]);
        removed[c] = true, par[c] = p;
        for (int x: edges[c])
            if (!removed[x]) build(x, c);
        return c;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    Centroids c(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        c.add_edge(u, v);
    }

    int root = c.build();

    vector<int> adj[n];
    for (int i = 0; i < n; i++) {
        if (c.par[i] != -1)
            adj[c.par[i]].push_back(i);
    }

    char ans[n];
    function<void(int, char)> dfs = [&](int v, char c) {
        ans[v] = c;
        for (int x: adj[v])
            dfs(x, c + 1);
    };

    dfs(root, 'A');

    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];

    return 0;
}
