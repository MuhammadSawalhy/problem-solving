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
vector<int> depth;
vector<int> parent;

int calc_k(int node, int h) {
  int myk = 0;

  depth[node] = 0;
  for (auto child : adjlist[node]) {
    myk += calc_k(child, h);
    if (parent[child] == node)
      depth[node] = max(depth[node], depth[child] + 1);
  }

  if (parent[node] == 0)
    return myk;

  if (h == 1 || depth[node] != 0 && depth[node] % (h - 1) == 0) {
    // modify the adjlist and recompute depth[parent[node]]
    parent[node] = 0;
    myk++;
  }

  return myk;
}

void solve() {
  int n, k;
  cin >> n >> k;
  adjlist.clear(), adjlist.resize(n);
  parent.clear(), parent.resize(n);
  depth.clear(), depth.resize(n);
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p, p--;
    adjlist[p].push_back(i);
    parent[i] = p;
  }

  vector<int> parent_backup = parent;
  auto valid = [&](int h) {
    int myk = 0;
    depth = vector<int>(n);
    parent = parent_backup;
    for (auto child : adjlist[0])
      myk += calc_k(child, h);
    return myk <= k;
  };

  int s = 0, e = n - 1;
  while (e - s > 1) {
    int mid = (s + e) >> 1;
    if (valid(mid)) {
      e = mid;
    } else {
      s = mid;
    }
  }

  cout << e << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--)
    solve();

  return 0;
}
