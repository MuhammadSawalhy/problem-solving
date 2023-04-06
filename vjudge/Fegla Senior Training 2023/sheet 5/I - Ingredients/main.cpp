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

const int N = 101;
int s, n, m, stores[8];
int dp[N][N][1 << 8];
vector<pair<int, int>> adj[N];
vector<int> dist[8];

vector<int> dijkstra(int s) {
    vector<int> prev(n + 1);
    vector<ll> dist(n + 1, 1e18);

    typedef pair<ll, int> item;
    priority_queue<item, deque<item>, greater<item>> qu;
    qu.push({0, s});
    dist[s] = 0;

    while (!qu.empty()) {
        auto [d, i] = qu.top();
        qu.pop();

        if (dist[i] < d) continue;
        for (auto [j, D]: adj[i]) {
            if (dist[j] > D + d) {
                prev[j] = i;
                dist[j] = D + d;
                qu.push({dist[j], j});
            }
        }
    }

    // for (int i = e; i != s; i = prev[i]);
    return dist;
}

int solve(int i, int j, int taken) {
    if (taken == (1 << s) - 1) return 0;
    int &ans = dp[i][j][taken];
    if (~ans) return ans;

    ans = 1e9;

    for (int k = 0; k < s; k++) {
        if (taken >> k & 1) continue;
        ans = min(ans, solve(stores[k], j, taken | (1 << k)) + dist[k][i]);
        ans = min(ans, solve(i, stores[k], taken | (1 << k)) + dist[k][j]);
    }

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    cin >> s;
    for (int i = 0; i < s; i++)
        cin >> stores[i];

    for (int i = 0; i < s; i++)
        dist[i] = dijkstra(stores[i]), debug(dist[i]);

    memset(dp, -1, sizeof dp);

    int a, b;
    cin >> a >> b;
    cout << solve(a, b, 0);

    return 0;
}
