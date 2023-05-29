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

const int mod = 1e9 + 7;

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
    vector<int> dp(n);
    dp[n - 1] = 1;
    vis[n - 1] = true;

    function<void(int)> dfs = [&](int i) {
        if (vis[i]) return;
        vis[i] = true;
        for (auto j: adj[i]) {
            dfs(j);
            dp[i] = (dp[i] + dp[j]) % mod;
        }
    };

    dfs(0);

    cout << dp[0] << '\n';

    return 0;
}
