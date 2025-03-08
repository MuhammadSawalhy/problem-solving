#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define int long long

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif


struct State {
    int i, j, cost;
    State(int i, int j, int cost) : i(i), j(j), cost(cost) {}
    bool operator<(const State &other) const {
        return cost > other.cost;
    }
};

void solve() {
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vector<int> adj1[n], adj2[n];

    int m1;
    cin >> m1;
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }

    int m2;
    cin >> m2;
    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }

    int dist[n][n];
    bool vis[n][n];
    memset(vis, 0, sizeof vis);
    memset(dist, 0x3f, sizeof dist);
    const int inf = dist[0][0];

    priority_queue<State> pq;
    int ans = inf;
    pq.push({s1 - 1, s2 - 1, 0});

    while (pq.size()) {
        int i = pq.top().i, j = pq.top().j, cost = pq.top().cost;
        pq.pop();
        debug(i, j, cost);
        if (vis[i][j]) continue;
        vis[i][j] = 1;
        dist[i][j] = cost;
        for (auto ni: adj1[i]) {
            for (auto nj: adj2[j]) {
                if (!vis[ni][nj]) {
                    pq.push({ni, nj, cost + abs(ni - nj)});
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (vis[i][i]) {
            for (auto ni: adj1[i]) {
                for (auto nj: adj2[i]) {
                    if (ni == nj && vis[ni][nj] && dist[i][i] == dist[ni][nj])
                        ans = min(ans, dist[i][i]);
                }
            }
        }
    }

    if (ans == inf) ans = -1;
    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug(t);
        solve();
    }

    return 0;
}
