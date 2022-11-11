// Date: 15-10-2022
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
  unsigned ll a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  unsigned ll ans = 0;

  unsigned ll m = 0;
  for (int i = 0; i < n; i++) {
    m = a[i];
    ans += m;
    for (int j = i + 1; j < n; j++) {
      m = max(m, a[j]);
      ans += m;
    }
  }

  cout << ans << endl;

  return 0;
}
