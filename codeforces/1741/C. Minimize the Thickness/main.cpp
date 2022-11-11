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
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int s = 0;
  int ans = n;
  for (int i = 0; i < n - 1; i++) {
    s += a[i];

    int ok = true;
    int ss = 0;
    int an = i + 1;
    int k = i;
    for (int j = i + 1; j < n; j++) {
      ss += a[j];
      if (ss == s) {
        ss = 0;
        an = max(j - k, an);
        k = j;
      } else if (ss > s) {
        ok = false;
        break;
      }
    }

    if (ss != 0) { // last one didn't complete the segment
      ok = false;
    }

    if (ok)
      ans = min(an, ans);
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
