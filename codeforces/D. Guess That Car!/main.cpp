// Date: 15-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef LOCAL
#include "debug.hpp"
#endif

void solve() {
  int n, m;
  cin >> n >> m;
  int cars[n][m];
  long long sumc = 0;
  long long sumyc = 0;
  long long sumxc = 0;
  long long sumyc2 = 0;
  long long sumxc2 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int xc = j * 4 + 2, yc = i * 4 + 2;
      cin >> cars[i][j];
      sumc += cars[i][j];
      sumyc += yc * cars[i][j];
      sumxc += xc * cars[i][j];
      sumyc2 += 1LL * yc * yc * cars[i][j];
      sumxc2 += 1LL * xc * xc * cars[i][j];
      debug(xc,yc,cars[i][j]);
    }
  }

  long long time = LONG_LONG_MAX;
  pair<int, int> point;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      int x = j * 4, y = i * 4;
      long long tx = sumc * x * x - 2LL * sumxc * x + sumxc2;
      long long ty = sumc * y * y - 2LL * sumyc * y + sumyc2;
      long long t = tx + ty;
      if (t < time) {
        time = t;
        point = {i, j};
      }
    }
  }

  cout << time << endl;
  cout << point.first << " " << point.second << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  solve();
  return 0;
}
