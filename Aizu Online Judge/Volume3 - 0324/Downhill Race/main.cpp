#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif


struct Edge {
    int next, t1, t2;
};

const int N = 1001;
int dist[N][N], order[N], ord = 0;
vector<Edge> g[N];

void topo(int i) {
    for (auto &e: g[i])
        if (order[e.next] == 0) topo(e.next);
    assert(order[i] == 0);
    order[i] = N - (ord++);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, p;
    cin >> n >> p;
    for (int i = 0; i < p; i++) {
        int s, e, t1, t2;
        cin >> s >> e >> t1 >> t2;
        g[s].push_back({e, t1, t2});
    }

    topo(1);
    using S = array<int, 3>;
    priority_queue<S, vector<S>, greater<S>> pq;
    pq.push({0, 1, 1});
    memset(dist, 0x3f, sizeof dist);
    dist[1][1] = 0;

    debug_itr(order, n + 1);
    while (pq.size()) {
        auto [d, u, v] = pq.top();
        pq.pop();
        if (dist[u][v] < d) continue;
        if (u == v) {
            for (auto [u2, tu1, tu2]: g[u]) {
                for (auto [v2, tv1, tv2]: g[v]) {
                    int dd = u == v && u2 == v2 ? d + tu1 + tv2 : d + tu1 + tv1;
                    if (dist[u2][v2] > dd) {
                        dist[u2][v2] = dd;
                        pq.push({dd, u2, v2});
                    }
                }
            }
            continue;
        }
        if (order[u] > order[v]) swap(u, v);
        for (auto [u2, tu1, tu2]: g[u]) {
            int dd = d + tu1;
            if (dist[u2][v] > dd) {
                dist[u2][v] = dd;
                pq.push({dd, u2, v});
            }
        }
    }

    cout << dist[n][n] << endl;

    return 0;
}
