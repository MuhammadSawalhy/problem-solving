// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

const int N = 1e5 + 5;
vector<pair<int, int>> adj[N];
int dist[N];
int with_discount[N];

void calc() {
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pair<int, int>> qu;
    qu.push({0, 0});
    dist[0] = 0;

    while (qu.size()) {
        auto [d, u] = qu.top();
        qu.pop();
        d *= -1;

        if (d > dist[u]) continue;

        for (auto [v, c]: adj[u]) {
            if (dist[u] + c < dist[v]) {
                dist[v] = dist[u] + c;
                qu.push({-dist[v], v});
            }
        }
    }
}

void calc_with_discount() {
    memset(with_discount, 0x3f, sizeof with_discount);
    priority_queue<pair<int, int>> qu;
    qu.push({0, 0});
    with_discount[0] = 0;

    while (qu.size()) {
        auto [d, u] = qu.top();
        qu.pop();
        d *= -1;

        if (d > with_discount[u]) continue;

        for (auto [v, c]: adj[u]) {
            int D = min(with_discount[u] + c, dist[u] + c / 2);
            if (D < with_discount[v]) {
                with_discount[v] = D;
                qu.push({-with_discount[v], v});
            }
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0, u, v, c; i < m; i++) {
        cin >> u >> v >> c;
        u--, v--;
        adj[u].emplace_back(v, c);
    }

    calc();
    debug_itr(dist, n);
    calc_with_discount();

    cout << with_discount[n - 1];

    return 0;
}
