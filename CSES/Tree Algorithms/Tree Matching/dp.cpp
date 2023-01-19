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

int n, ans;
const int N = 2e5;
vector<int> adj[N];
vector<vector<int>> dp(N, vector<int>(2, -1));

int dfs(int i, int p, bool taken) {
    if (~dp[i][taken]) return dp[i][taken];
    int ans = 0;
    vector<pair<int, int>> a;

    for (int j: adj[i]) {
        if (j == p) continue;
        int b = dfs(j, i, false);
        ans += b;
        if (!taken)
            a.push_back({b, dfs(j, i, true) + 1});
    }

    int sna = ans;
    for (auto [x, y] : a) {
        ans = max(ans, sna - x + y);
    }

    return dp[i][taken] = ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b, a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << dfs(0, 0, false) << endl;

    debug_itr(dp, n, 1);

    return 0;
}
