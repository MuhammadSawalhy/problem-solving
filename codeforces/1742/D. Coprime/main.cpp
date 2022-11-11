// Date: 13-10-2022
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#endif

void solve() {
  int n;
  cin >> n;
  map<int, int> indm;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    indm[a] = i;
  }

  vector<pair<int, int>> ind;

  for (auto [n, i] : indm) {
    ind.push_back({n, i});
  }

  debug(ind);

  int ans = -1;
  for (int i = 0; i < ind.size(); i++) {
    for (int j = i; j < ind.size(); j++) {
      if (gcd(ind[i].first, ind[j].first) == 1) {
        ans = max(ans, ind[i].second + ind[j].second + 2);
      }
    }
  }

  cout << ans << endl;
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
