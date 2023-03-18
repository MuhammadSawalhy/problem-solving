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

const int N = 1e5 + 1;
int n, ini[N], goal[N];
vector<int> adj[N], ans;

void dfs(int i, int p, int x, int y) {
    bool need = ini[i] ^ goal[i] ^ y;
    if (need)
        ans.push_back(i);
    for (auto child: adj[i]) {
        if (child == p) continue;
        dfs(child, i, y ^ need, x);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        cin >> ini[i];
    for (int i = 1; i <= n; i++)
        cin >> goal[i];

    dfs(1, 1, 0, 0);

    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << endl;

    return 0;
}
