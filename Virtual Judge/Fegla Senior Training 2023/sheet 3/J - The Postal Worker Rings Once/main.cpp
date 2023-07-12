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

    pair<int, int> path(bool circuit = false) {
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
            return {start, end};
        }

        return {-1, -1};
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

long long dijkstra(int s, int e, vector<vector<pair<int, int>>> &adj) {
    int n = adj.size();
    vector<int> prev(n + 1);
    vector<ll> dist(n + 1, 1e18);

    typedef pair<ll, int> item;
    priority_queue<item, deque<item>, greater<item>> qu;
    qu.push({0, s});
    dist[s] = 0;

    while (!qu.empty()) {
        auto [d, i] = qu.top();
        qu.pop();

        if (dist[i] < d) continue;
        for (auto [j, D]: adj[i]) {
            if (dist[j] > D + d) {
                prev[j] = i;
                dist[j] = D + d;
                qu.push({dist[j], j});
            }
        }
    }

    // for (int i = e; i != s; i = prev[i]);
    return dist[e];
}

void solve() {
    string s;
    cin >> s;
    if (!cin) return;

    vector<vector<pair<int, int>>> adj(26);

    ll cost = 0;
    int m = 0;
    do {
        m++;
        cost += s.size();
        adj[s.front() - 'a'].push_back({s.back() - 'a', s.size()});
        adj[s.back() - 'a'].push_back({s.front() - 'a', s.size()});
    } while (cin >> s, s != "deadend");

    auto [i, j] = UndirectedEulerian<int>(26, m, adj).path(true);

    if (j != -1) {
        cost += dijkstra(i, j, adj);
    }

    cout << cost << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (cin)
        solve();

    return 0;
}
