// Date: 17-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

struct union_find {
  vector<int> rank, parent;
  int forests;

  union_find(int n) {
    forests = n;
    rank = vector<int>(n);
    parent = vector<int>(n);
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }

  bool connected(int x, int y) { return find(x) == find(y); }

  int find(int x) {
    if (parent[x] == x)
      return x;
    return parent[x] = find(parent[x]);
  }

  bool uni(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)
      return false;
    if (rank[y] > rank[x])
      swap(x, y);
    parent[y] = x;
    if (rank[x] == rank[y])
      rank[x]++;
    return true;
  }
};

struct edge {
  int from, to;
  double w;
  edge(int from, int to, double weight) : from(from), to(to), w(weight) {}
  bool operator<(edge &e) { return w < e.w; }
};

pair<double, vector<edge>> mst_kruskal(vector<edge> edges, int v) {
  union_find uf(v + 1);
  double cost = 0;
  vector<edge> mst_edges;

  sort(edges.rbegin(), edges.rend());

  while (!edges.empty()) {
    auto &e = edges.back();
    edges.pop_back();
    if (uf.uni(e.from, e.to)) {
      cost += e.w;
      mst_edges.push_back(e);
    }
  };

  if (mst_edges.size() != v - 1)
    return {INFINITY, {}};

  return {cost, mst_edges};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int n;
  cin >> n;
  vector<vector<long long>> paths(n, vector<long long>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> paths[i][j];

  vector<edge> edges;

  for (int i = 0; i < n; i++) {
    if (paths[i][i] != 0) {
      cout << "NO" << endl;
      return 0;
    }
    for (int j = i + 1; j < n; j++) {
      edges.push_back(edge(i, j, paths[i][j]));
      if (paths[i][j] != paths[j][i] || paths[i][j] == 0) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }

  auto [cost, mst_edges] = mst_kruskal(edges, n);
  if (cost == INFINITY) {
    cout << "NO" << endl;
    return 0;
  }

  // let's try to construct the paths our self from hte MST
  // can't use Floyd algorithm
  vector<int> adj[n];
  map<pair<int, int>, int> weight;
  for (auto e: mst_edges) {
    adj[e.from].push_back(e.to);
    adj[e.to].push_back(e.from);
    weight[{e.from, e.to}] = e.w;
    weight[{e.to, e.from}] = e.w;
  }

  bool ok = true;
  function<void(int, int, int, long long)> dfs = [&](int root, int parent, int node, long long cost) {
    debug(root, node, cost);
    if (!ok) return;
    if (cost != paths[root][node]) {
      ok = false;
      return;
    }
    for (auto child: adj[node]) {
      if (child == parent) continue;
      dfs(root, node, child, cost + weight[{node, child}]);
    }
  };

  for (int i = 0; i < n; i++) {
    dfs(i, -1, i, 0);
  }

  debug(ok);

  cout << (ok ? "YES" : "NO") << endl;
  return 0;
}
