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
  ll a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      bool flag = true;
      for (int k = i + 1; k < j; k++) {
        flag = flag && a[k] <= a[i] && a[k] <= a[j];
      }
      ans += flag;
    }
  }

  cout << ans << endl;

  return 0;
}
