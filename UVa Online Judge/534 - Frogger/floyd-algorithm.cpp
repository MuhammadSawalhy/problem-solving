// Date: 09-10-2022
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#endif

int n;

void solve() {
  int x[n], y[n];
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];

  int d[n][n] = ;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cout << fixed << setprecision(3);
  int t = 0;
  while (cin >> n, n) {
    cout << "Scenario #" << ++t << endl;
    solve();
    cout << endl;
  }

  return 0;
}
