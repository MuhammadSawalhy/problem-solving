// Date: 29-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  vector<pair<int, int>> depth; // depth, node

  for (int i = 1; i < n; i++) {
    int u;
    cin >> u;
    u--;
    adj[u].push_back(i);
  }

  function<void(int, int)> dfs = [&](int node, int d) {
    bool leaf = true;

    for (auto child : adj[node]) {
      leaf = false;
      dfs(child, d + 1);
    }

    if (leaf)
      depth.push_back({d, node});
  };

  dfs(0, 0);

  sort(all(depth));
  vector<int> val(n);
  int cnt = 0;
  while (depth.size()) {
    val[depth.back().second] = ++cnt;
    depth.pop_back();
  }

  for (int i = 0; i < n; i++) {
    if (val[i] == 0) {
      val[i] = ++cnt;
    }
  };

  vector<int> a;
  function<void(int, int)> doit = [&](int node, int d) {
  };

  return 0;
}
