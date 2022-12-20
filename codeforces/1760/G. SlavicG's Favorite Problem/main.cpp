// Date: 21-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  a--, b--;
  vector<vector<int>> adj(n);
  map<pair<int, int>, int> weight;
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    weight[{u, v}] = w;
    weight[{v, u}] = w;
  }

  set<int> sa, sb;

  function<void(int, int, int, int, set<int> &)> dfs = [&](int node, int parent, int stop, int x, set<int> &s) {
    debug(parent, node, x);
    if (node == stop) return;
    if (node != b)
      s.insert(x);
    for (auto child: adj[node]) {
      if (child == parent) continue;
      dfs(child, node, stop, x ^ weight[{node, child}], s);
    }
  };

  // only consider the sortest path
  dfs(a, a, b, 0, sa);
  dfs(b, b, -1, 0, sb);

  debug(sa);
  debug(sb);
  debug(weight);

  for (auto i: sa) {
    if (sb.count(i)) {
      cout << "YES" << endl;
      return;
    }
  }

  cout << "NO" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
