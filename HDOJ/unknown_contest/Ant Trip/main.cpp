#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e5 + 5;
vector<int> adj[N], deg(N);
vector<bool> vis(N, false);

int cnt = 0, tot = 0;
void dfs(int i) {
    tot++;
    cnt += deg[i] & 1;
    vis[i] = true;
    for (auto j: adj[i]) {
        if (!vis[j]) dfs(j);
    }
}

void solve() {
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++, deg[v]++;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        cnt = 0, tot = 0;
        dfs(i);
        if (tot > 1) ans += max(1, cnt / 2);
    }

    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
        deg[i] = 0, vis[i] = false;
        adj[i].clear();
    }
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    while (cin >> n >> m) {
        solve();
    }

    return 0;
}
