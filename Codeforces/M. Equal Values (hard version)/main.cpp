// Date: 12-10-2022
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#endif

void solve() {
  int n, q;
  cin >> n >> q;
  long long a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);

  long long s[n];
  s[0] = a[0];
  for (int i = 1; i < n; i++)
    s[i] = a[i], s[i] += s[i - 1];

  while (q--) {
    long long x;
    cin >> x;
    int j = lower_bound(a, a + n, x) - a;

    long long ans = s[n - 1] - (j > 0 ? s[j - 1] : 0);
    ans -= x * (n - j);

    if (j > 0) {
      ans += x * j;
      ans -= s[j - 1];
    }

    cout << ans << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  solve();

  return 0;
}
