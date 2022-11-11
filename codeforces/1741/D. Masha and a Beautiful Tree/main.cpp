// Date: 11-10-2022
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#endif

int ans = 0;
bool ok = true;
vector<int> p;

pair<int, int> doit(int low, int high) {
  if (low == high) {
    return {p[low], p[low]};
  }

  int mid = (low + high) >> 1;
  auto [lmin, lmax] = doit(low, mid);
  auto [rmin, rmax] = doit(mid + 1, high);

  if (rmax < lmin) {
    ans++;
    if (rmax > lmin) {
      ok = false;
    }
  } else {
    if (lmax > rmin) {
      ok = false;
    }
  }

  return {min(rmin, lmin), max(lmax, rmax)};
}

void solve() {
  int m;
  cin >> m;
  p = vector<int>(m);
  for (int i = 0; i < m; i++)
    cin >> p[i];

  ok = true;
  ans = 0;

  doit(0, m - 1);

  if (ok)
    cout << ans << endl;
  else
    cout << -1 << endl;
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
