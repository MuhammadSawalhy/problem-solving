// ﷽
#include <map>
#include <array>
#include <queue>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

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

int n, m;
const int N = 2001;
int c[N];
int dp[N][N];
vector<int> adj[N];

void bfs() {
    queue<array<int, 2>> qu;
    qu.push({0, n - 1});

    dp[0][n - 1] = 0;
    // overall comlexity will be O(M^2 + N^2)
    while (qu.size()) {
        // each i, j will appear only once
        auto [i, j] = qu.front();
        int d = dp[i][j];
        qu.pop();

        // overall computations need will have complexity of O(M^2)
        for (auto k: adj[i]) {
            for (auto l: adj[j]) {
                // if (c[l] == c[k] || (d + 1 > dp[k][l] && dp[k][l] != -1)) continue;
                // when I used (d + 1 > ) it resulted in TLE due to repeatition of i, j over and over
                // which will result at the end in an overall solution with complexity of O(M^4 + N^4)
                if (c[l] == c[k] || (d + 1 >= dp[k][l] && dp[k][l] != -1)) continue;
                dp[k][l] = d + 1;
                qu.push({k, l});
            }
        }
    }
}

void solve() {
    cin >> n >> m;

    for (int i = 0; i < N; i++)
        adj[i].clear();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;
    }

    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0, u, v; i < m; i++)
        cin >> u >> v, u--, v--, adj[u].push_back(v), adj[v].push_back(u);

    if (c[n - 1] == c[0]) {
        cout << -1 << endl;
        return;
    }

    bfs();
    cout << dp[n - 1][0] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
