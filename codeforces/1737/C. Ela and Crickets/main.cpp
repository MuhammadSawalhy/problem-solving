// Date: 07-10-22
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
  vector<int> r(3);
  vector<int> c(3);
  for (int i = 0; i < 3; i++)
    cin >> r[i] >> c[i];
  int x, y;
  cin >> x >> y;

  auto check = [&](int j) {
    // check if the origin of the L shape
    int q = (j + 1) % 3, k = (j + 2) % 3;
    return r[j] == r[q] && c[j] == c[k] || r[j] == r[k] && c[j] == c[q];
  };

  int i = 0;
  while (!check(i)) {
    i++;
  }

  bool corner = (r[i] == 1 || r[i] == n) && (c[i] == 1 || c[i] == n);

  if (corner) {
    if (x == r[i] || y == c[i]) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    if (r[i] % 2 == x % 2 || c[i] % 2 == y % 2) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
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
