// ----------------------------------------------------------------------------
// Problem : D. Edge Split
// Author  : Muahmmad Assawalhy
// Date    : 06-09-22
// ----------------------------------------------------------------------------

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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef unsigned long long ull;

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
    forests--;
    parent[y] = x;
    if (rank[x] == rank[y])
      rank[x]++;
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--) {
    int n, m;
    cin >> n >> m;
    vb ans(m);
    vi u(m);
    vi v(m);
    union_find ufred(n);
    union_find ufblue(n);
    vector<pair<int, int>> edges;
    vector<vector<int>> con_edges(n);

    bool ok = true;
    for (int i = 0; i < m; i++) {
      cin >> u[i] >> v[i];
      u[i]--;
      v[i]--;
      con_edges[u[i]].push_back(i);
      con_edges[v[i]].push_back(i);
      edges.push_back({u[i], v[i]});
      if (!ufred.uni(u[i], v[i])) {
        ans[i] = true;
        if (!ufblue.uni(u[i], v[i])) {
          // we have to remove the cycle
          ok = false;
        }
      }
    }

    if (!ok) {
      // loop over blue
      for (int i = 0; i < m; i++) {
        if (!ans[i])
          continue;
        ans.assign(m, false);
        ufred = union_find(n);
        ufred.uni(edges[i].first, edges[i].second);
        for (int j = 0; j < m; j++) {
          if (j == i)
            continue;
          if (!ufred.uni(edges[j].first, edges[j].second)) {
            ans[j] = true;
          }
        }
      }
    }

    for (int i = 0; i < m; i++)
      cout << int(ans[i]);
    cout << endl;
  }
  return 0;
}
