// Date: 29-10-2022
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
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(all(a));
  long long ans = 0;

  for (int i = 1; i < n - 1; i++) {
    ans = max(ans, a[n - 1] - a[i - 1] + a[i] - a[i - 1]);
  }

  for (int i = n - 1; i > 1; i--) {
    ans = max(ans, a[i] - a[0] + a[i] - a[i - 1]);
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
