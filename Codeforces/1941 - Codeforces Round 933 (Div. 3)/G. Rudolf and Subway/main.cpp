// ﷽
// https://codeforces.com/contest/1941/problem/G

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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    vector<int> colors;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        colors.push_back(c);
        u--, v--;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    int b, e;
    cin >> b >> e;
    b--, e--;

    if (b == e) {
        cout << 0 << endl;
        return;
    }

    sort(all(colors));
    vector<vector<int>> nodes(m);

    for (int i = 0; i < n; i++) {
        for (auto &[j, c]: adj[i]) {
            c = lower_bound(all(colors), c) - colors.begin();
            nodes[c].push_back(i);
        }
    }

    // bfs, where each node is visited only once
    vector<bool> nvis(n);
    vector<bool> cvis(m);
    queue<pair<int, int>> q; // queue for colors

    for (auto [j, c]: adj[b]) {
        q.push({c, 0});
        cvis[c] = true;
    }

    while (q.size()) {
        auto [c, steps] = q.front();
        q.pop();

        // loop over the color nodes
        for (auto i : nodes[c]) {
            if (nvis[i]) continue;
            nvis[i] = true;
            if (i == e) {
                cout << steps + 1 << endl;
                return;
            }

            for (auto &[j, c]: adj[i]) {
                if (cvis[c]) continue;
                q.push({c, steps + 1});
                cvis[c] = true;
            }
        }
    }
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
