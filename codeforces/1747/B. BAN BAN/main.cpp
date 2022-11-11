// Date: 04-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> ans;

  for (int i = 0; i < n / 2; i++) {
    ans.push_back({i * 3 + 1, (n - i) * 3 - 1});
  }
  
  if (n & 1) {
    ans.push_back({ 0, (n + 1) / 2 * 3 - 1 });
  }

  cout << ans.size() << endl;
  for (auto [l, r]: ans)
    cout << l + 1 << " " << r + 1 << endl;
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
