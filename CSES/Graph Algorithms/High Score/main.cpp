// ﷽
#include <bits/stdc++.h>

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> edges;
    vector<long long> dist(n, (long long)1e18);
    dist[0] = 0;

    int inf = 1e18;
    vector<vector<int>> mat(n, vector<int>(n, inf));

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c, a--, b--;
        mat[a][b] = -c;
        edges.push_back({a, b, -c});
    }

    for (int i = 0; i < n; i++) {
        for (auto [a, b, c]: edges) {
            if (dist[b] > dist[a] + c) {
                dist[b] = dist[a] + c;
            }
        }
    }

    vector<bool> vis(n);
    bool ok = true, reached = false;
    vector<int> vert;
    function<void(int, int)> dfs = [&](int i, int p) {
        if (dist[i] > dist[p] + mat[p][i]) ok = false, vert.push_back(i);
        if (vis[i]) return;
        vis[i] = true;
        for (int j = 0; j < n; j++)
            if (mat[i][j] != inf)
                dfs(j, i);
    };

    function<void(int, int)> dfs2 = [&](int i, int p) {
        if (i == n - 1) reached = true;
        if (vis[i]) return;
        vis[i] = true;
        for (int j = 0; j < n; j++)
            if (mat[i][j] != inf)
                dfs2(j, i);
    };

    dfs(0, 0);

    vis.assign(n, false);
    if (!ok)
        for (int v : vert)
            dfs2(v, v);

    if (reached) {
        cout << -1 << endl;
        return 0;
    }

    cout << -dist[n - 1] << endl;

    return 0;
}
