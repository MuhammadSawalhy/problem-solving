// Date: 04-10-22
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
vector<bool> vis;
vector<int> ini;
vector<int> goal;
vector<int> ans;

void dfs(int i, bool grand_flips, bool flips) {
  if (vis[i])
    return;
  vis[i] = true;

  if (goal[i] ^ ini[i] ^ grand_flips) {
    grand_flips ^= 1;
    ans.push_back(i);
  }

  for (auto c : adjlist[i]) {
    dfs(c, flips, grand_flips);
  }
}

void solve() {
  int n;
  cin >> n;
  adjlist.resize(n);
  vis.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
  }

  ini.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> ini[i];
  }

  goal.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> goal[i];
  }

  dfs(0, 0, 0);

  cout << ans.size() << endl;
  for (auto i : ans)
    cout << i << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  solve();
  return 0;
}
