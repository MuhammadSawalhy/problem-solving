// ﷽
// https://cses.fi/problemset/task/1692

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vii vector<pii>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

template<typename Edge>
class DirectedEulerian {
public:
    int n;
    vector<vector<pair<int, Edge>>> adj;

    DirectedEulerian(int n) : n(n) {
        adj.assign(n, vector<pair<int, Edge>>());
    }

    void add_edge(int u, int v, Edge edge) {
        debug(u, v, edge);
        adj[u].emplace_back(v, edge);
    }

    pair<pair<int, int>, vector<Edge>> path(bool circuit = false) {
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

        if (!((in == 0 && out == 0) || (in == 1 && out == 1 && !circuit))) {
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

        dfs(start, {}, path);

        path.pop_back();
        reverse(all(path));

        return {{start, end}, path};
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

void solve() {
    int n;
    cin >> n;

    if (n == 1) return void(cout << "10\n");
    if (n == 2) return void(cout << "00110\n");

    DirectedEulerian<bool> eu(1 << (n - 1));

    for (int i = 0; i < 1 << (n - 1); i++) {
        int suff = i & ((1 << (n - 2)) - 1);
        eu.add_edge(i, suff << 1 | 0, 0);
        eu.add_edge(i, suff << 1 | 1, 1);
    }

    auto [endpoints, path] = eu.path(true);

    debug(endpoints);
    debug(path);

    assert(endpoints.first == endpoints.second && endpoints.first == 0);

    string ans(n - 1, '0');

    for (int i = 0; i < sz(path); i++) {
        ans += '0' + path[i];
    }

    cout << ans << '\n';
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
