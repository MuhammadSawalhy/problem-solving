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

const int mod = 1e9 + 7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n];
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c, a--, b--;
        adj[a].emplace_back(b, c);
    }

    priority_queue<pair<int, int>> pq;
    vector<int> price(n), cnt(n), cntmin(n), cntmax(n);
    pq.push({0, 0});

    while (pq.size()) {
        auto [d, i] = pq.top();
        pq.pop();
        d *= -1;

        for (auto [j, c]: adj[i]) {
            pq.push({-(d + c), j});
        }
    }

    return 0;
}
