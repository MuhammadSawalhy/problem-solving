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

    int n, m, a, b;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    debug_itr(adj, adj + n);

    vector<int> parent(n, -1);
    vector<bool> vis(n);
    queue<int> qu;
    qu.push(0);
    vis[0] = true;

    while (qu.size()) {
        debug(qu);
        int i = qu.front();
        qu.pop();
        if (i == n - 1) {
            vector<int> path;
            while (~i) {
                path.push_back(i);
                i = parent[i];
            }
            cout << path.size() << endl;
            for (i = path.size() - 1; ~i; i--)
                cout << path[i] + 1 << " ";
            cout << endl;
            return 0;
        }
        for (int a: adj[i]) {
            if (!vis[a]) {
                qu.push(a);
                parent[a] = i;
                vis[a] = true;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
