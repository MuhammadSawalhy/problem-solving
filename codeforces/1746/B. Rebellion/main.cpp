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
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = 0;
  int i = 0, j = n - 1;
  while (i < j) {
    while (j >= 0 && a[j] == 1) {
      j--;
    }

    while (i < n && a[i] == 0) {
      i++;
    }

    if (i > j)
      break;

    ans++;
    j--;
    i++;
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
