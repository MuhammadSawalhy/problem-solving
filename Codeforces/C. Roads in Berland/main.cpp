// Date: 22-09-22
#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#endif

constexpr int N = 300;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  vector<vector<int>> mat(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
    }
  }

  int k;
  cin >> k;
  long long ans = 0;

  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);

  while (k--) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;

    mat[a][b] = min(mat[a][b], c);
    mat[b][a] = mat[a][b];

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        mat[i][j] = min(mat[i][j], mat[i][a] + mat[a][j]);
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        mat[i][j] = min(mat[i][j], mat[i][b] + mat[b][j]);
    }

    ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        ans += mat[i][j];
      }
    }

    cout << ans;
    if (k)
      cout << " ";
  }

  cout << endl;

  return 0;
}
