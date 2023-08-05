// ﷽
// https://cses.fi/problemset/task/1693
// CSES -> CSES Problem Set -> Teleporters Path

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
class DirectedEulerian {
public:
    int n, m;
    vector<vector<pair<int, Edge>>> adj;
    DirectedEulerian(int n, int m, const vector<vector<pair<int, Edge>>> &adj) : adj(adj), n(n), m(m) {}

    vector<Edge> path(bool circuit = false) {
        vector<Edge> path;
        int in = 0, out = 0;

        calc_deg();
        int start = -1, end = -1;
        for (int i = 0; i < n; i++) {
            if (indeg[i] > outdeg[i])
                in += indeg[i] - outdeg[i], end = i;
            else if (indeg[i] < outdeg[i])
                out += outdeg[i] - indeg[i], start = i;
        }

        if (m == 0 || !((in == 0 && out == 0) || (in == 1 && out == 1 && !circuit))) {
            return {};
        }

        if (start == -1) {
            assert(end == -1);
            for (int i = 0; i < n; i++) {
                if (outdeg[i] > 0) {
                    start = end = i;
                    break;
                }
            }
        }
        
        if (start != 0 || end != n - 1) {
            return {};
        }


        dfs(start, {}, path);

        path.pop_back();
        reverse(all(path));

        return path;
    }

private:
    vector<int> indeg, outdeg;

    void calc_deg() {
        indeg.assign(n, 0);
        outdeg.assign(n, 0);
        for (int i = 0; i < n; i++) {
            outdeg[i] = adj[i].size();
            for (auto &j: adj[i]) indeg[j.first]++;
        }
    }

    void dfs(int i, Edge e, vector<Edge> &path) {
        while (outdeg[i] > 0)
            outdeg[i]--, dfs(adj[i][outdeg[i]].first, adj[i][outdeg[i]].second, path);
        path.push_back(e);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b, a--, b--;
        adj[a].push_back({b, a});
    }

    auto path = DirectedEulerian<int>(n, m, adj).path();

    if (path.size() < m) {
        cout << "IMPOSSIBLE\n";
        exit(0);
    }

    path.push_back(n - 1);
    for (int i : path) cout << i + 1 << ' ';

    return 0;
}
