// Date: 18-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef LOCAL
#include "debug.hpp"
#endif

void solve() {
  ll n, s;
  cin >> n >> s;
  int a[n];
  ll su = 0;
  int m = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    su += a[i];
    m = max(a[i], m);
  }

  s -= (1LL * m * (m + 1) / 2) - su;
  debug(su, (1LL * m * (m + 1) / 2), s);

  for (int i = m + 1; s > 0; i++) {
    s -= i;
  }

  if (s == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
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
