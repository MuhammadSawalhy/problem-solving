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

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

const int N = 100'001;
vector<array<int, 3>> adj[N];
int ans[N], vis[N];

void dfs(int i) {
    vis[i] = 1;
    for (auto [j, e, dir]: adj[i]) {
        if (ans[e] == 0) ans[e] = dir;
        if (vis[j] == 0) {
            dfs(j);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0, u, v; i < n; i++) {
        cin >> u >> v, u--, v--;
        adj[u].push_back({v, i, 1});
        adj[v].push_back({u, i, 2});
    }

    for (int i = 0; i < n; i++) {
        dfs(i);
    }

    for (int i = 0; i < m; i++)
        cout << ans[i] - 1;

    return 0;
}
