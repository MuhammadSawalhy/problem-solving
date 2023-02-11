// ﷽
#include <bits/stdc++.h>

using namespace std;

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

int ans = 1e9;

void dfs(int i, int p, int c, vector<int> adj[], int dist[]) {
    if (dist[i] < c) return;
    dist[i] = c;
    for (auto j: adj[i]) {
        if (j == p) continue;
        dfs(j, i, c + 1, adj, dist);
    }
}

void solve() {
    int n, c;
    cin >> n >> c, c--;
    int sq[n - 1];
    vector<int> adj[n];
    int dist[n];
    memset(dist, 0x3f, sizeof dist);
    for (int i = 0; i < n - 1; i++) {
        cin >> sq[i], sq[i]--;
    }

    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(c, c, 0, adj, dist);
    debug_itr(dist, n);

    ans = 1e9;
    for (int i = 0; i < n - 1; i++) {
        ans = min(ans, dist[sq[i]]);
        cout << ans << " ";
        dfs(sq[i], sq[i], 0, adj, dist);
    }

    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
