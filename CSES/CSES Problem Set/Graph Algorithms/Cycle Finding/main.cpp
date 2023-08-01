// ﷽
#include <bits/stdc++.h>
#include <random>

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

struct edge {
    int a, b, cost;
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<edge> edges(m);
    vector<ll> parent(n), dist(n, 1e18);

    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        a--, b--;
        edges.push_back({a, b, c});
    }

    int x;
    for (int i = 0; i < n; i++) {
        x = -1;
        for (auto e: edges) {
            if (dist[e.a] + e.cost < dist[e.b]) {
                dist[e.b] = dist[e.a] + e.cost;
                parent[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "NO" << endl;
    } else {
        vector<int> cycle;
        // because neg cycles gives to theirs neighbours in the last iteration of Bellman-Form algorithm
        // we need to do make x stuck in a cycle so we will iterate n times and to to the parent
        for (int i = 0; i < n; i++)
            x = parent[x];

        cycle.push_back(x);
        x = parent[x];
        while (x != cycle[0]) {
            cycle.push_back(x);
            x = parent[x];
        }
        cycle.push_back(cycle[0]);
        reverse(all(cycle));

        cout << "YES" << endl;
        for (auto node: cycle)
            cout << node + 1 << " ";
    }

    return 0;
}
