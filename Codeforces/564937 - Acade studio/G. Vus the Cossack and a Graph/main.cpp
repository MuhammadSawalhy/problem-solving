#include <bits/stdc++.h>
using namespace std;

#define int int32_t
const int N = 1e6 + 1;
int deg[N];
bitset<N * 2> done;
pair<int, int> edges[N * 2];
vector<int> adj[N], path;

void dfs(int i) {
    while (adj[i].size()) {
        int j = adj[i].back();
        adj[i].pop_back();
        if (done[j]) continue;
        done[j] = true;
        dfs(edges[j].first == i ? edges[j].second : edges[j].first);
    }
    path.push_back(i);
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[i] = {u, v};
        adj[u].push_back(i);
        adj[v].push_back(i);
        deg[u]++, deg[v]++;
    }

    vector<int> ini(deg, deg + n + 1);

    for (int i = 0; i < n; i++) {
        if (deg[i] & 1) {
            edges[m] = {i, n};
            adj[i].push_back(m);
            adj[n].push_back(m);
            m++;
        }
    }

    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++) {
        if (adj[i].empty()) continue;
        path.clear();
        dfs(i);
        vector<bool> del(path.size());
        int available = 0;

        for (int j = 1; j + 1 < path.size(); j += 2) {
            del[j] = true;
            if (n != max(path[j], path[j + 1])) deg[path[j]]--, deg[path[j + 1]]--;
        }

        for (int j = 0; j + 1 < path.size(); j++) {
            if (max(path[j], path[j + 1]) == n && !del[j]) available++;
        }

        for (int j = 0; j + 1 < path.size(); j++) {
            if (max(path[j], path[j + 1]) != n) {
                if (del[j] && (deg[path[j]] < (ini[path[j]] + 1) / 2 || deg[path[j + 1]] < (ini[path[j + 1]] + 1) / 2) && available) {
                    available--;
                    del[j] = false;
                    deg[path[j]]++, deg[path[j + 1]]++;
                }
                if (!del[j]) {
                    ans.push_back({path[j], path[j + 1]});
                }
            }
        }
    }

    cout << ans.size() << endl;
    for (auto [i, j]: ans) {
        cout << i + 1 << ' ' << j + 1 << endl;
    }

    return 0;
}
