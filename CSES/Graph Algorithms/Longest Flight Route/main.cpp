// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> adj[n];

    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b, a--, b--;
        adj[a].push_back(b);
    }

    vector<bool> vis(n);
    vector<pair<int, int>> dp(n, {-1e9, -1}); // cnt, next
    // top sort? may be and go backward
    // but it may work with simple dfs fron node 1 (index 0)
    dp[n - 1] = {1, -1};
    vis[n - 1] = true;

    function<void(int)> dfs = [&](int i) {
        if (vis[i]) return;
        vis[i] = true;
        for (auto j: adj[i]) {
            dfs(j);
            if (dp[i].first < dp[j].first + 1) {
                dp[i].first = dp[j].first + 1;
                dp[i].second = j;
            }
        }
    };

    dfs(0);

    if (dp[0].first < 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << dp[0].first << '\n';
    int i = 0;
    while (~i) {
        cout << i + 1 << " ";
        i = dp[i].second;
    }

    return 0;
}
