// Date: 30-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

void solve() {
  int n, k;
  cin >> n >> k;

  if (n == 1 || k == 0) {
    cout << 0 << endl;
    return;
  }

  k = min(k, n / 2);
  ll ans = 1LL * 2 * k * n + k - 1LL * 4 * k * (k + 1) / 2;

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
