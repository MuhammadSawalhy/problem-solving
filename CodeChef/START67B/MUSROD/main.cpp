// Date: 30-11-2022
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
  vector<int> a(n);
  vector<int> b(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }


  vector<int> order(n);
  iota(all(order), 0);
  sort(all(order), [&](auto l, auto r) {
    return 1.0 * a[l] / b[l] > 1.0 * a[r] / b[r];
  });

  for (auto i : order) {
    cerr << 1.0 * a[i] / b[i] << " ";
  }
  cerr << endl;

  debug(order);

  ll ans = 0;
  ll x = 0;
  for (auto i: order) {
    ans += x * b[i];
    x += a[i];
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
