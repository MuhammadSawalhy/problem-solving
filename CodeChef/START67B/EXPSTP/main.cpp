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
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  int ans = abs(a - x) + abs(b - y);
  debug(ans, a, b, x, y, a - x, b - y);

  ans = min(ans, a + x);
  ans = min(ans, a + y);
  ans = min(ans, a + n - x + 1);
  ans = min(ans, a + n - y + 1);

  ans = min(ans, n - a + 1 + x);
  ans = min(ans, n - a + 1 + y);
  ans = min(ans, n - a + 1 + n - x + 1);
  ans = min(ans, n - a + 1 + n - y + 1);

  ans = min(ans, b + x);
  ans = min(ans, b + y);
  ans = min(ans, b + n - x + 1);
  ans = min(ans, b + n - y + 1);

  ans = min(ans, n - b + 1 + x);
  ans = min(ans, n - b + 1 + y);
  ans = min(ans, n - b + 1 + n - x + 1);
  ans = min(ans, n - b + 1 + n - y + 1);

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
