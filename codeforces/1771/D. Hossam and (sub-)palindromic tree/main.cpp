// Date: 11-12-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef LOCAL
#include "debug.hpp"
#endif

void solve() {
    int n;
    string letter;
    cin >> n >> letter;
    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 1;
    int dp[n][n][26];
    memset(dp, -1, sizeof dp);

    function<int(int, int, int, int)> dfs = [&](int root, int parent, int node, int mx) -> int {
        char r = letter[root], n = letter[node];
        if (r == n) mx += 2;
        
    };

    for (int i = 0; i < n; i++) {
        for (auto child : adj[i]) {
            dfs(i, i, child, 1);
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
