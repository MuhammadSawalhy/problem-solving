// Date: 21-11-2022
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
  ll a[n + 1];
  ll l[n + 1], r[n + 1];
  l[0] = 0;
  r[n + 1] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    l[i] = max(l[i - 1], a[i]);
  }

  for (int i = n; i > 0; i--) {
    r[i] = max(r[i + 1], a[i]);
  }

  for (int i = 1; i <= n; i++) {
    int mx = max(l[i - 1], r[i + 1]);
    cout << a[i] - mx << " ";
  }
  cout << endl;
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
