// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

template<typename Edge>
class UndirectedEulerian {
public:
    int n, m;
    vector<vector<pair<int, Edge>>> adj;
    UndirectedEulerian(int n, int m, const vector<vector<pair<int, Edge>>> &adj) : adj(adj), n(n), m(m) {}

    vector<Edge> path(bool circuit = false) {
        vector<Edge> path;

        cnt.clear();
        calc_deg();
        int start = -1, end = -1, odds = 0;
        for (int i = 0; i < n; i++) {
            if (deg[i] & 1) {
                odds++;
                if (~start)
                    end = i;
                else
                    start = i;
            }
        }

        if (m == 0 || !(odds == 0 || (odds == 2 && !circuit))) {
            return {};
        }

        start = 0;

        dfs(start, -1, {}, path);

        path.pop_back();
        reverse(all(path));

        return path;
    }

private:
    vector<int> deg;
    map<pair<int, int>, int> cnt;

    void calc_deg() {
        deg.assign(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto &j: adj[i]) {
                deg[j.first]++;
                if (i == j.first)
                    deg[j.first]++;
                if (i <= j.first)
                    cnt[{i, j.first}]++;
            }
        }
    }

    void dfs(int i, int p, Edge e, vector<Edge> &path) {
        cnt[{min(i, p), max(i, p)}]--;
        while (adj[i].size()) {
            auto [j, E] = adj[i].back();
            adj[i].pop_back();
            if (cnt[{min(i, j), max(i, j)}] == 0) continue;
            dfs(j, i, E, path);
        }
        path.push_back(e);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b, a--, b--;
        adj[a].push_back({ b, b });
        if (a != b)
            adj[b].push_back({ a, a });
    }

    UndirectedEulerian eu(n, m, adj);
    auto path = eu.path(true);

    if (path.size() < m) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    debug(path);

    cout << path.back() + 1 << ' ';
    for (auto i : path) {
        cout << i + 1 << ' ';
    }

    return 0;
}
