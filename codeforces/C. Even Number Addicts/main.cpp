// Date: 30-09-22
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

bool dp[2][101][101];

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int odds = 0, evens = 0;
  for (auto &i : a) {
    cin >> i;
    if (i % 2 == 0)
      evens++;
    else
      odds++;
  }
  debug(odds, evens);
  cout << (dp[0][odds][evens] ? "Alice" : "Bob") << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  for (int i = 1; i <= 100; i++)
    dp[0][0][i] = true;
  for (int i = 1; i <= 100; i += 4) {
    dp[0][i][0] = false;
    dp[0][i + 1][0] = false;
  }
  for (int i = 3; i <= 100; i += 4) {
    dp[0][i][0] = true;
    dp[0][i + 1][0] = true;
  }

  for (int i = 1; i <= 100; i++)
    dp[1][0][i] = false;
  for (int i = 1; i <= 100; i += 4) {
    dp[1][i][0] = true;
    dp[1][i + 1][0] = true;
  }
  for (int i = 3; i <= 100; i += 4) {
    dp[1][i][0] = false;
    dp[1][i + 1][0] = false;
  }

  // odds
  for (int i = 1; i <= 100; i++) {
    // evens
    for (int j = 1; j <= 100; j++) {
      if (i % 2 == 0) {
        dp[0][i][j] = !dp[1][i][j - 1] || !dp[1][i - 1][j];
        dp[1][i][j] = !dp[0][i][j - 1] || !dp[0][i - 1][j];
      } else {
        dp[1][i][j] = !dp[1][i][j - 1] || !dp[1][i - 1][j];
        dp[0][i][j] = !dp[0][i][j - 1] || !dp[0][i - 1][j];
      }
    }
  }

  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--) {
    solve();
  }
  return 0;
}
