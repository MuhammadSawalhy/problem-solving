// ﷽
// https://codeforces.com/contest/1915/problem/G

#include <bits/stdc++.h>
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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

void solve() {
    // read graph
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    int s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<array<int, 3>> q;
    vector<vector<int>> dist(n, vector<int>(1001, 1e18));
    int ans = 1e18;
    dist[0][s[0]] = 0;
    q.push_back({0, s[0], 0});
    for (int qi = 0; qi < (int)q.size(); qi++) {
        auto [d, x, i] = q[qi];

        if (i == n - 1) {
            ans = min(ans, d);
            continue;
        }

        if (dist[i][x] < d) continue;

        for (auto [j, c]: adj[i]) {
            int D = d + x * c;
            int xx = min(x, s[j]);
            if (dist[j][xx] > D) {
                dist[j][xx] = D;
                q.push_back({D, xx, j});
            }
        }
    }

    cout << ans << '\n';
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
