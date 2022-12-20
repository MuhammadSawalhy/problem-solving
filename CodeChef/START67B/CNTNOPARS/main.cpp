// Date: 02-12-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

void solve() {
  int n;
  cin >> n;
  ll p[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }

  ll ans = 0;

  // O(n*n) -- how to enhance this thing ??
  /* for (int k = 1; k <= n; k++) { */
  /*   map<ll, int> fr; */
  /*   for (int i = 1; i <= n; i++) { */
  /*     ll val = p[i] - 1ll * i * k; */
  /*     fr[val]++; */
  /*     ans += fr[-(val)]; */
  /*   } */
  /* } */

  map<int, map<ll, int>> fr;
  for (int i = 1; i <= n; i++) {
    int mink = max(1, ((int) p[i] + i) / (n + i));
    int maxk = (n + (int) p[i]) / (1 + i);
    for (int k = mink; k <= maxk; k++) {
      ll val = p[i] - 1ll * i * k;
      fr[k][val]++;
      ans += fr[k][-val];
    }
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
