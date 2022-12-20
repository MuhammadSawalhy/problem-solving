// Date: 21-11-2022
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
  ll a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int zeros[n], ones[n];
  zeros[n - 1] = ones[n - 1] = 0;
  int o = 0, z = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ones[i] = o;
    o += a[i];
  }

  for (int i = n - 1; ~i; i--) {
    zeros[i] = z;
    if (a[i]) {
      ans += zeros[i];
    }
    z += 1 - a[i];
  }

  ll org = ans;
  for (int i = 0; i < n; i++) {
    // try to flip
    if (a[i]) {
      // 1 -> 0
      ans = max(ans, org - zeros[i] + ones[i]);
    } else {
      // 0 -> 1
      ans = max(ans, org + zeros[i] - ones[i]);
    }
    debug(i, ans);
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
