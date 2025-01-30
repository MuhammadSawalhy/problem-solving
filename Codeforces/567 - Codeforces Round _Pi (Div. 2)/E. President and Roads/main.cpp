#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

struct E {
    int u, v, w;
};

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    --s, --t;
    vector<vector<pair<int, int>>> g(n), rg(n), G(n);
    vector<E> e(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        e[i] = {u, v, w};
        g[u].emplace_back(v, w);
        rg[v].emplace_back(u, w);
    }

    using P = pair<long long, int>;
    auto dijkstra = [&](int src, const vector<vector<pair<int, int>>> &gr) {
        vector<long long> d(n, INF);
        priority_queue<P, vector<P>, greater<>> pq;
        d[src] = 0;
        pq.emplace(0, src);
        while (!pq.empty()) {
            auto [dist, u] = pq.top();
            pq.pop();
            if (dist > d[u]) continue;
            for (auto &[v, w]: gr[u]) {
                if (d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    pq.emplace(d[v], v);
                }
            }
        }
        return d;
    };
    vector<long long> ds = dijkstra(s, g), dt = dijkstra(t, rg);
    long long D = ds[t];

    for (int i = 0; i < n; i++)
        for (auto [j, w]: g[i])
            if (ds[i] + w + dt[j] == D) G[i].push_back({j, w});

    set<array<int, 3>> yes;
    {
        vector<long long> d(n, INF);
        priority_queue<P, vector<P>, greater<>> pq;
        d[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [dist, u] = pq.top();
            pq.pop();
            if (dist > d[u]) continue;
            if (pq.size() == 0 && G[u].size() == 1) {
                yes.insert({u, G[u][0].first, G[u][0].second});
            }
            for (auto &[v, w]: G[u]) {
                if (d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    pq.emplace(d[v], v);
                }
            }
        }
    }

    for (auto [u, v, w]: e) {
        if (yes.count({u, v, w})) {
            cout << "YES\n";
        } else {
            long long min_w = D - ds[u] - dt[v] - 1;
            if (min_w > 0) {
                cout << "CAN " << w - min_w << '\n';
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}

