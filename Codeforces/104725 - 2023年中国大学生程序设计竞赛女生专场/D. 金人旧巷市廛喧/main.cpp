#include <bits/stdc++.h>
using namespace std;
#define int long long

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif


const int INF = 1e9;

class MinCostMaxFlow {
public:
    struct Edge {
        int u, cap, cost, v;
    };

    MinCostMaxFlow(int n) : graph(n), dist(n), in_queue(n), parent(n), parent_edge(n) {}

    void add_edge(int from, int to, int capacity, int cost) {
        graph[from].push_back({to, capacity, cost, (int) graph[to].size()});
        graph[to].push_back({from, 0, -cost, (int) graph[from].size() - 1});
    }

    pair<int, int> get(int source, int sink) {
        int max_flow = 0, min_cost = 0;
        while (spfa(source, sink)) {

            int path_flow = INF;
            for (int v = sink; v != source; v = parent[v]) {
                Edge &e = graph[parent[v]][parent_edge[v]];
                path_flow = min(path_flow, e.cap);
            }

            int cost = 0;
            for (int v = sink; v != source; v = parent[v]) {
                Edge &e = graph[parent[v]][parent_edge[v]];
                e.cap -= path_flow;
                graph[v][e.v].cap += path_flow;
                cost += path_flow * e.cost;
            }

            if (cost > 100) break;
            min_cost += cost;
            max_flow += path_flow;
        }
        return {max_flow, min_cost};
    }

private:
    vector<vector<Edge>> graph;
    vector<int> dist;
    vector<bool> in_queue;
    vector<int> parent, parent_edge;

    bool spfa(int source, int sink) {
        fill(dist.begin(), dist.end(), INF);
        fill(in_queue.begin(), in_queue.end(), false);
        dist[source] = 0;
        queue<int> q;
        q.push(source);
        in_queue[source] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            in_queue[u] = false;

            for (int i = 0; i < graph[u].size(); ++i) {
                Edge &e = graph[u][i];
                if (e.cap > 0 && dist[u] + e.cost < dist[e.u]) {
                    dist[e.u] = dist[u] + e.cost;
                    parent[e.u] = u;
                    parent_edge[e.u] = i;
                    if (!in_queue[e.u]) {
                        q.push(e.u);
                        in_queue[e.u] = true;
                    }
                }
            }
        }
        return dist[sink] != INF;
    }
};

int node_id(int x, int y, int in_out, int m) {
    return (x * m + y) * 2 + in_out;
}

signed main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<pair<int, int>> start_points(k), end_points(k);
    for (int i = 0; i < k; ++i) {
        cin >> start_points[i].first >> start_points[i].second;
        --start_points[i].first;
        --start_points[i].second;
    }
    for (int i = 0; i < k; ++i) {
        cin >> end_points[i].first >> end_points[i].second;
        --end_points[i].first;
        --end_points[i].second;
    }

    int total_nodes = 2 + n * m * 2;
    MinCostMaxFlow mcmf(total_nodes);
    int source = total_nodes - 1, sink = total_nodes - 2;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int in_node = node_id(i, j, 0, m);
            int out_node = node_id(i, j, 1, m);

            if (grid[i][j] == -1) {
                mcmf.add_edge(in_node, out_node, 0, 0);
            } else if (grid[i][j] == 1) {
                mcmf.add_edge(in_node, out_node, 1, 0);
            } else {
                mcmf.add_edge(in_node, out_node, 1, 1);
            }

            for (auto [dx, dy]: vector<pair<int, int>>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                int ni = i + dx, nj = j + dy;
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    mcmf.add_edge(out_node, node_id(ni, nj, 0, m), 1, 0);
                }
            }
        }
    }

    for (auto [x, y]: start_points) {
        mcmf.add_edge(source, node_id(x, y, 0, m), 1, 0);
    }

    for (auto [x, y]: end_points) {
        mcmf.add_edge(node_id(x, y, 1, m), sink, 1, 0);
    }

    auto [f, c] = mcmf.get(source, sink);
    debug(f, c);


    if (c) assert(f > 0 && c > 0);
    cout << 100 * f - c << endl;
    return 0;
}
