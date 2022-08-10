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

typedef complex<double> point;
#define angle(v) (atan2((a).y, (a).x))
#define length(v) (hypot((a).y, (a).x))
#define normalize(v) ((a) / length(a))

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
  int from, to, w;
  edge(int from, int to, int weight) : from(from), to(to), w(weight) {}
  bool operator<(edge &e) { return w < e.w; }
};

void mst_kruskal(vector<edge> &edges, vector<edge> &prev, int v) {
  union_find uf(v + 1);

  int prev_coutner = 0;
  for (edge &e : prev) {
    prev_coutner += uf.uni(e.from, e.to);
  }

  if (prev_coutner == v - 1) {
    cout << "No new highways need" << endl;
    return;
  }

  sort(rall(edges));

  while (!edges.empty()) {
    auto &e = edges.back();
    edges.pop_back();
    if (uf.uni(e.from, e.to)) {
      cout << e.to << " " << e.from << endl;
    }
  };
}

int main(int argc, char *argv[]) {

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<pair<int, point>> towns;
    vector<edge> possible_ways;
    vector<edge> existing_ways;

    for (int i = 1; i <= n; i++) {
      double x, y;
      cin >> x >> y;
      point pos = {x, y};

      for (auto &other : towns) {
        int dx = other.second.real() - x;
        int dy = other.second.imag() - y;
        int d = dx * dx + dy * dy;
        edge e(i, other.first, d);
        possible_ways.push_back(e);
      }

      towns.push_back({i, pos});
    }

    int m;
    cin >> m;
    while (m--) {
      int i, j;
      cin >> i >> j;
      edge e(i, j, 0);
      existing_ways.push_back(e);
    }

    mst_kruskal(possible_ways, existing_ways, n);

    if (t)
      cout << endl;
  }

  return 0;
}
