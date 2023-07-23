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

struct DSU {
    vector<int> size, parent;
    int forests;

    DSU(int n) {
        forests = n;
        size.assign(n, 1);
        parent.resize(n);
        iota(all(parent), 0);
    }

    bool connected(int x, int y) { return find(x) == find(y); }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool uni(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        forests--;
        parent[y] = x;
        size[x] += size[y];
        return true;
    }
};

struct Edge {
    int from, to;
    long long weight;
    Edge(int from, int to, long long weight) : from(from), to(to), weight(weight) {}
    bool operator<(Edge &e) { return weight < e.weight; }
};

pair<long long, vector<Edge>> mst_kruskal(vector<Edge> &edges, int n) {
    DSU uf(n + 1);
    double cost = 0;
    vector<Edge> mst_edges;

    sort(edges.rbegin(), edges.rend());

    while (!edges.empty()) {
        auto &e = edges.back();
        edges.pop_back();
        if (uf.uni(e.from, e.to)) {
            cost += e.weight;
            mst_edges.push_back(e);
        }
    };

    if (mst_edges.size() != n - 1)
        return {1e18, {}};

    return {cost, mst_edges};
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges;

    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c, a--, b--;
        edges.push_back({a, b, c});
    }

    auto [cost, mst] = mst_kruskal(edges, n);
    if (cost == 1e18) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << cost << endl;
    }

    return 0;
}
