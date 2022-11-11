// Date: 13-10-2022
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#endif

int n;

pair<int, int> intersect(pair<int, int> a, pair<int, int> b) {
  int l = max(a.first, b.first);
  int r = min(a.second, b.second);
  if (l > r)
    l = r;
  return {l, r};
}

void solve() {
  pair<int, int> x = {-1e7, 1e7};
  pair<int, int> y = {-1e7, 1e7};
  pair<int, int> z = {-1e7, 1e7};

  while (n--) {
    int a, b, c, s;
    cin >> a >> b >> c >> s;
    x = intersect(x, {a, a + s});
    y = intersect(y, {b, b + s});
    z = intersect(z, {c, c + s});
  }

  cout << (x.second - x.first) * (y.second - y.first) * (z.second - z.first) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  while (cin >> n, n)
    solve();

  return 0;
}
