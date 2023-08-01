// ﷽
// https://codeforces.com/group/ARb1vgiFev/contest/465051/problem/D
// Codeforces -> Team Contest #9 2023 -> D. DnD Dice

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int nums[] = {4, 6, 8, 12, 20};
  vector<int> d;

  for (auto n : nums) {
    int x;
    cin >> x;

    for (int i = 0; i < x; i++) {
      d.push_back(n);
    }
  }

  int N = d.size(), M = N * 20;
  __int128 dp[N + 1][M + 1];
  memset(dp, 0, sizeof dp);

  dp[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int s = 0; s <= M; s++) {
      for (int j = 1; j <= d[i]; j++) {
        if (s + j <= M)
          dp[i + 1][s + j] += dp[i][s];
      }
    }
  }

  // debug_itr(dp[N], (int32_t)M + 1);

  vector<pair<__int128, int>> sums;

  for (int s = 0; s <= M; s++) {
    if (dp[N][s])
      sums.push_back({dp[N][s], s});
  }

  sort(all(sums));
  reverse(all(sums));

  for (auto [_, s] : sums)
    cout << s << ' ';

  return 0;
}
