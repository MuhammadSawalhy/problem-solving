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
    UndirectedEulerian(int n, int m, vector<vector<pair<int, Edge>>> adj) : adj(adj), n(n), m(m) {}

    vector<Edge> path(bool circuit = false, int start = 0) {
        vector<Edge> path;

        cnt.clear();
        calc_deg();
        int odds = 0;
        for (int i = 0; i < n; i++) {
            if (deg[i] & 1) {
                odds++;
            }
        }

        if (m == 0 || !(odds == 0 || (odds == 2 && !circuit))) {
            return {};
        }

        dfs(start, -1, {}, path);

        path.pop_back();
        reverse(all(path));

        return path;
    }

private:
    vector<int> deg;
    map<array<int, 3>, int> cnt;

    void calc_deg() {
        deg.assign(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto &j: adj[i]) {
                deg[j.first]++;
                if (i == j.first)
                    deg[j.first]++;
                if (i <= j.first)
                    cnt[{i, j.first, j.second}]++;
            }
        }
    }

    void dfs(int i, int p, Edge e, vector<Edge> &path) {
        cnt[{min(i, p), max(i, p), e}]--;
        while (adj[i].size()) {
            auto [j, E] = adj[i].back();
            adj[i].pop_back();
            if (cnt[{min(i, j), max(i, j), E}] == 0) continue;
            dfs(j, i, E, path);
        }
        path.push_back(e);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int x, y, s;

    while (true) {
        cin >> x >> y;
        if (x == 0) break;
        vector<vector<pair<int, int>>> adj(1995);

        int m = 0, start = 1e9;
        do {
            if (start == 1e9)
                start = min(x, y);
            m++;
            cin >> s;
            debug(s);
            adj[x].push_back({y, s});
            if (x != y)
                adj[y].push_back({x, s});
        } while (cin >> x >> y, x);

        for (int i = 0; i < 1995; i++) {
            sort(all(adj[i]), [](pair<int, int> l, pair<int, int> r) { return l.second > r.second; });
        }

        auto path = UndirectedEulerian<int>(1995, m, adj).path(true, start);

        if (path.size() != m) {
            cout << "Round trip does not exist.\n";
        } else {
            for (int i = 0; i < m; i++) {
                cout << path[i] << " \n"[i == m - 1];
            }
        }
        cout << "\n";
    }

    return 0;
}
