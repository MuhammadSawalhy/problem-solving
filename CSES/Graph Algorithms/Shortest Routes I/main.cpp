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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long long> dist(n, LONG_LONG_MAX);
    dist[0] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.push({0, 0});

    vector<pair<long long, int>> adj[n];

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--,b--;
        adj[a].push_back({c, b});
    }

    while (pq.size()) {
        auto [d, i] = pq.top();
        d *= -1;
        pq.pop();
        if (dist[i] < d) continue;
        for (auto [dd, j] : adj[i]) {
            if (d + dd < dist[j]) {
                pq.push({-(d+dd), j});
                dist[j] = d + dd;
            }
        }
    }

    for (int i = 0; i < n; i++) 
        cout << dist[i] << " ";

    return 0;
}
