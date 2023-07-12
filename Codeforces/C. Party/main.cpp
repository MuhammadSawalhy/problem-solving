// Date: 19-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int n;
  cin >> n;

  vector<vector<int>> adj(n + 1);
  for (int i = 1; i <= n; i++) {
    int m;
    cin >> m;
    m = max(m, 0);
    adj[m].push_back(i);
  }

  function<int(int)> max_depth = [&](int node) {
    int d = 1;
    for (auto child : adj[node]) {
      d = max(d, 1 + max_depth(child));
    }
    return d;
  };

  cout << max_depth(0) - 1 << endl;

  return 0;
}
