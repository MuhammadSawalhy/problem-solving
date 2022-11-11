// Date: 15-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

void solve() {
  int n;
  cin >> n;

  vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    ans[a] = i;
  }

  for (int i = n; i >= 1; i--)
    cout << ans[i] << " ";
  cout << endl;
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
