// Date: 11-10-2022
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
  vector<int> b(n);
  vector<bool> dp(n);

  for (int i = 0; i < n; i++)
    cin >> b[i];

  for (int i = 0; i < n; i++) {
    if (i == 0 && b[i] < n)
      dp[b[i]] = true;
    else if (i + b[i] < n && dp[i - 1])
      dp[i + b[i]] = true;
    if (i - b[i] - 1 >= 0 && dp[i - b[i] - 1] || i - b[i] == 0)
      dp[i] = true;
  }

  cout << (dp[n - 1] ? "YES" : "NO") << endl;
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
