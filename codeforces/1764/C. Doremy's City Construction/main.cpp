// Date: 26-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef LOCAL
#include "debug.hpp"
#endif

void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);

  if (a[0] == a[n - 1]) {
    cout << n / 2 << endl;
    return;
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    while (i > 0 && i < n && a[i] == a[i - 1]) i++;
    ans = max(ans, 1LL * (i) * (n - i));
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
