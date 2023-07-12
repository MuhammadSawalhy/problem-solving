#include "bits/stdc++.h"

using namespace std;

#define ll long long
const int MAXN = 100100;

int t, n;
int dp[2][MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;
  while (t--) {

    cin >> n;

    for (int i = 0; i < 2; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] = 0;
      }
    }

    int x;
    for (int i = 1; i <= n; i++) {
      cin >> x;
      dp[i & 1][x] = dp[~i & 1][x] + 1;
    }

    for (int i = 1; i <= n; i++)
      cout << max(dp[0][i], dp[1][i]) << " \n"[i == n];
  }
}
