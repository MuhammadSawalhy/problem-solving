#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()

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
  int from, to, w, i;
  edge(int from, int to, int weight) : from(from), to(to), w(weight) {}
  bool operator<(edge &e) { return w < e.w; }
};

pair<int, vector<edge>> mst_kruskal(vector<edge> edges, int v) {
  int cost = 0;
  union_find uf(v + 1);
  vector<edge> mst_edges;
  sort(rall(edges));

  while (!edges.empty()) {
    auto &e = edges.back();
    edges.pop_back();
    if (uf.uni(e.from, e.to)) {
      cost += e.w;
      mst_edges.push_back(e);
    }
  };

  if (sz(mst_edges) != v - 1)
    return {INT_MAX, {}};

  return {cost, mst_edges};
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<edge> edges;

  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    edge e(a, b, c);
    e.i = edges.size();
    edges.push_back(e);
  }

  auto mst = mst_kruskal(edges, n);
  int cost1 = mst.first;

  int cost2 = INT_MAX;
  for (edge &e : mst.second) {
    int w = edges[e.i].w;
    edges[e.i].w = 301;
    auto mst = mst_kruskal(edges, n);
    cost2 = min(cost2, mst.first);
    edges[e.i].w = w;
  }

  cout << cost1 << " " << cost2 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_cases;
  cin >> t_cases;
  while (t_cases--)
    solve();
  return 0;
}
