// ﷽
// https://codeforces.com/contest/1866/problem/C
// Codeforces -> COMPFEST 15 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred) -> C. Completely Searching for Inversions

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

vector<bool> vis;
vector<int> order;
vector<vector<pair<int, int>>> adj;
vector<array<int, 3>> dp;

void dfs(int i) {
    if (vis[i]) return;
    vis[i] = true;
    for (auto [j, _]: adj[i])
        dfs(j);
    order.push_back(i);
}

void solve() {
    int n;
    cin >> n;

    order.clear();
    dp.assign(n, {0, 0, 0});
    vis.assign(n, false);
    adj.assign(n, {});

    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;

        while (s--) {
            int j, w;
            cin >> j >> w, j--;
            adj[i].emplace_back(j, w);
        }
    }

    dfs(0);

    debug(adj);
    debug(order);

    for  (int i = 0; i < n; i++) {
        int zeros = 0, ones = 0;
        for (auto [j, w] : adj[order[i]]) {
            dp[order[i]][0] += dp[j][0];
            dp[order[i]][1] += dp[j][1];
            dp[order[i]][2] += dp[j][2];
            dp[order[i]][w]++;

            dp[order[i]][2] += (w == 1) * dp[j][0];
            dp[order[i]][2] += (w == 0) * ones;
            dp[order[i]][2] += dp[j][0] * ones;
            dp[order[i]][2] %= 998244353;

            zeros += w == 0;
            zeros += dp[j][0];
            ones += w == 1;
            ones += dp[j][1];
        }
    }

    cout << dp[0][2] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    solve();

    return 0;
}
