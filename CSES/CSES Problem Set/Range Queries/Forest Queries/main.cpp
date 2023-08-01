// Date: 12-10-2022
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#endif

void solve() {
  int n, q;
  cin >> n >> q;

  int forest[n + 1][n + 1];
  memset(forest, 0, sizeof forest);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char c;
      cin >> c;
      forest[i][j] = c == '*';
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      forest[i][j] += forest[i - 1][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      forest[i][j] += forest[i][j - 1];
    }
  }

  while (q--) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    cout << forest[x][y] - forest[x][b - 1] - forest[a - 1][y] +
                forest[a - 1][b - 1]
         << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  solve();

  return 0;
}
