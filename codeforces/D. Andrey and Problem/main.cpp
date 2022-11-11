// Date: 14-10-2022
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#endif

void solve() {
  int n;
  cin >> n;
  vector<double> p(n);
  double m = 0;
  for (int i = 0; i < n; i++)
    cin >> p[i], m = max(m, p[i]);

  double ans = 0;
  for (int i = 0; i < n; i++) {
    double pp = p[i];
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;
      pp *= 1 - p[j];
    }

    ans += pp;
  }

  cout << max(ans, m) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cout << fixed << setprecision(14);

  solve();

  return 0;
}
