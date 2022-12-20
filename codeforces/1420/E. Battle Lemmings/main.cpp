// Date: 25-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef LOCAL
#include "debug.hpp"
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int dp[n + 1][n + 1][n + 1];
  int dddp[n + 1][n + 1];
  memset(dp, 0, sizeof dp);
  memset(dddp, 0, sizeof dddp);

  for (int i = 1; i <= n; i++) {
    for (int ones = 1; ones <= i; ones++) {
      int zeros = (i - ones);
      for (int shift = 0; shift <= zeros; shift++) {
        int more = (zeros - shift) * shift;
        dp[i][ones][shift] = max(dp[i][ones][shift], dddp[i - shift - 1][ones - 1] + more);
        dddp[i][ones] = max(dddp[i][ones], dp[i][ones][shift]);
      }
    }
  }

  int ones = 0;
  for (int i = 0; i < n; i++)
    ones += a[i];
  cout << dddp[n][ones] << endl;

  return 0;
}
