// Date: 11-12-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll     long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

const int N = 2e3 + 1;
pair<int, int> info[N][N];

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

    vector<vector<pair<int, int>>> with_len(n);
    int dp[n][n];
    memset(dp, 0, sizeof dp);

    function<void(int, int, int, int, int)> process = [&](int v, int u, int gate, int prev, int len) {
        info[v][u] = {gate, prev};
        with_len[len].push_back({v, u});
        for (auto j: adj[u]) {
            if (j == prev) continue;
            process(v, j, gate, u, len + 1);
        }
    };

    int ans = 1;

    // clac dp for len = 0 and 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
        for (auto j: adj[i]) {
            dp[i][j] = 1 + (letter[i] == letter[j]);
            ans = max(ans, dp[i][j]);
            for (auto k: adj[j]) {
                if (k == i) continue;
                process(i, k, j, j, 2);
            }
        }
    }

    for (int len = 2; len < n; len++) {
        debug(len, with_len[len]);
        for (auto [v, u]: with_len[len]) {
            auto [a, b] = info[v][u];
            debug(v, a, b, u);
            dp[v][u] = max(dp[v][u], dp[a][u]);
            dp[v][u] = max(dp[v][u], dp[v][b]);
            if (letter[v] == letter[u]) {
                dp[v][u] = max(dp[v][u], dp[a][b] + 2);
            }
            ans = max(ans, dp[v][u]);
            debug(dp[v][u]);
        }
    }

    cout << ans << '\n';
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
