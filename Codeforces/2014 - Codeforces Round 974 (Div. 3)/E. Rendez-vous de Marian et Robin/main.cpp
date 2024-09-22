// ﷽
// https://codeforces.com/contest/2014/problem/E

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

vi dijkstra(int s, const vector<vector<pair<int, int>>> &adj, const vector<bool> &ish) {
    int n = adj.size();
    vector<vector<ll>> dist(n, vector<ll>(2, 1e18));

    typedef tuple<int, int, bool> item;
    priority_queue<item, deque<item>, greater<item>> qu;
    qu.push({0, s, ish[s]});
    dist[s][ish[s]] = 0;

    while (!qu.empty()) {
        auto [d, i, h] = qu.top();
        qu.pop();

        if (dist[i][h] < d) continue;
        for (auto [j, D]: adj[i]) {
            bool newh = h || ish[j];
            int newd = (h ? D / 2 : D) + d;
            if (dist[j][newh] > newd) {
                dist[j][newh] = newd;
                qu.push({newd, j, newh});
            }
        }
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = min(dist[i][0], dist[i][1]);
    }
    return ans;
}

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<bool> ish(n);
    for (int i = 0, x; i < h; i++) cin >> x, ish[x - 1] = true;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }


    auto x = dijkstra(0, adj, ish);
    auto y = dijkstra(n - 1, adj, ish);
    debug(n);
    debug(x);
    debug(y);

    int ans = 1e18;
    for (int i = 0; i < n; i++) {
        minit(ans, max(x[i], y[i]));
    }

    if (ans == 1e18) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
