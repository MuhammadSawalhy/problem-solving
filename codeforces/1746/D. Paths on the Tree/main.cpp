// Date: 15-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> s(n);
  vector<vector<int>> sons(n);
  map<pair<int, int>, ll> memo;

  for (int i = 1; i < n; i++) {
    int u;
    cin >> u;
    sons[u - 1].push_back(i);
  }

  for (int i = 0; i < n; i++)
    cin >> s[i];

  vector<array<int, 2>> f(n); // best and worst cases
  vector<array<ll, 2>> dp(n);

  function<void(int)> dfs = [&](int x) {
    int d = sons[x].size();
    for (auto son : sons[x]) {
      f[son][0] = f[x][0] / d;
      // TODO: why greedily choosing f[x][1] is correct?
      // I think to store the best case in f[son][1], and worst case in
      // f[son][0]
      f[son][1] = (f[x][1] + d - 1) / d;
      dfs(son);
    }
    // put whose (best - worst) is bigger at the beginning
    sort(sons[x].begin(), sons[x].end(), [&](int l, int r) {
      return dp[l][1] - dp[l][0] > dp[r][1] - dp[r][0];
    });
    for (auto k : {0, 1}) {
      int t = f[x][k];
      dp[x][k] = 1LL * s[x] * t;
      if (!d)
        continue;
      int cnt = t % d;
      for (int i = 0; i < d; i++) {
        if (f[x][0] / d * d + i < t)
          dp[x][k] += dp[sons[x][i]][1];
        else
          dp[x][k] += dp[sons[x][i]][0];
      }
    }
  };

  f[0] = {k, k};
  dfs(0);

  cout << dp[0][0] << endl;
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
