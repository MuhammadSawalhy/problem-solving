// ﷽
// https://codeforces.com/gym/102058/problem/B

#include <bits/stdc++.h>
using namespace std;

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, mm = 0;
    cin >> n >> m;

    vector<multiset<int>> adj(n);
    vector<set<int>> many(n);
    set<int> nodes;

    auto add_edge = [&](int u, int v) {
        adj[u].insert(v), adj[v].insert(u);
        if (adj[u].count(v) > 1) many[u].insert(v);
        if (adj[v].count(u) > 1) many[v].insert(u);
        nodes.insert(u), nodes.insert(v);
        mm++;
    };

    auto rem_edge = [&](int u, int v) {
        nodes.insert(u), nodes.insert(v);
        adj[u].erase(adj[u].find(v)), adj[v].erase(adj[v].find(u));
        if (adj[u].count(v) == 1) many[u].erase(v);
        if (adj[v].count(u) == 1) many[v].erase(u);
        mm--;
    };

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v, u--, v--;
        if (adj[u].count(v) == 0)
            add_edge(u, v);
    }

    while (nodes.size()) {
        int u = *nodes.begin();
        nodes.erase(u);

        auto many2 = many[u];
        while (many2.size()) {
            for (auto v: many2) rem_edge(u, v);
            many2 = many[u];
        }

        if (adj[u].size() == 2) {
            int x = *adj[u].begin(), y = *adj[u].rbegin();
            assert(x != y);
            rem_edge(u, x);
            rem_edge(u, y);
            add_edge(x, y);
        }
    }

    cout << (mm == 1 ? "Yes" : "No") << endl;
    return 0;
}
