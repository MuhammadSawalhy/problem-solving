// Date: 25-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef LOCAL
#include "debug.hpp"
#endif

void solve() {
  int n, x;
  cin >> n >> x;

  vector<int> ans(n + 1);
  ans[1] = x;
  ans[n] = 1;

  for (int i = 2; i <= n - 1; i++) {
    ans[i] = i;
  }

  debug(n, x);
  for (int i = x + 1; i <= n; i++) {
    // we need the furthest num that is divisor of n and multiple of i
    // it may be i itself
    // more fomally: n == 0 (mod x*i), what is x
    if (i % x == 0 && n % i == 0) {
      debug(true);
      ans[x] = i;
      x = i;
    }
  }

  if (x != n) {
    cout << -1 << endl;
    return;
  }

  for (int i = 1; i <= n; i++)
    cout << ans[i] << " ";
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
