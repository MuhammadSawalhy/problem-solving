// Date: 06-10-22
#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

vector<vector<int>> adjlist;

pair<int, int> dfs(int node, int parent) {
  int dia = 0;
  int mx[3] = {};

  for (auto child : adjlist[node]) {
    if (child == parent)
      continue;
    auto c = dfs(child, node);
    dia = max(dia, c.second);
    mx[0] = c.first + 1;
    sort(mx, mx + 3);
  }

  return {mx[2], max(dia, mx[1] + mx[2])};
}

void solve() {
  int n;
  cin >> n;
  adjlist.resize(n);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
  }

  auto ans = dfs(0, 0);
  cout << max(ans.first, ans.second) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  solve();

  return 0;
}
