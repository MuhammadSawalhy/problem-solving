// Date: 02-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int n;
  cin >> n;
  int a[n];
  map<int, int> fr;
  map<int, bool> valid;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    fr[a[i]]++;
  }

  for (int i = 0; i < n; i++) {
    int nextpower = 1;
    while (nextpower <= a[i]) {
      nextpower *= 2;
    }
    if (fr[nextpower - a[i]]) {
      if (a[i] == nextpower / 2 && fr[a[i]] == 1) {
        continue;
      }
      valid[a[i]] = true;
      valid[nextpower - a[i]] = true;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += !valid[a[i]];
  }

  cout << ans << endl;

  return 0;
}
