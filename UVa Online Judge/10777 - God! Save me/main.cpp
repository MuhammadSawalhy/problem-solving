// Date: 13-10-2022
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

  double prob = 0;
  double res = 0;

  vector<pair<int, double>> neg;
  for (int i = 0; i < n; i++) {
    int v;
    double p;
    cin >> v >> p;
    if (v > 0) {
      prob += p;
      res += v * p;
    } else {
      neg.push_back({-v, p});
    }
  }

  if (prob == 0) {
    cout << "God! Save me" << endl;
    return;
  }

  for (int i = 100000; i--;) {
    for (auto [v, p] : neg) {
      res += res * p + v * prob * p;
      prob += p * prob;
    }
  }

  cout << fixed << setprecision(2) << res / 100000.0 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int t;
  cin >> t;
  int c = 0;
  while (t--) {
    cout << "Case " << ++c << ": ";
    solve();
  }

  return 0;
}
