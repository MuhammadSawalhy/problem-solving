// Date: 16-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

void solve() {
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    while (a && a % 2 == 0) {
      cnt++;
      a >>= 1;
    }
  }

  vector<int> ind(n);

  for (int i = 1; i <= n; i++) {
    int r = 0;
    int j = i;
    while (j && j % 2 == 0) {
      r++;
      j >>= 1;
    }
    ind[i - 1] = r;
  }

  sort(ind.begin(), ind.end());

  if (cnt >= n) {
    cout << 0 << endl;
    return;
  }

  cnt = n - cnt;

  int op = 0;
  while (ind.size()) {
    int r = ind.back();
    ind.pop_back();
    if (r > cnt)
      continue;
    cnt -= r;
    op++;
    if (cnt == 0)
      break;
  }

  if (cnt) {
    cout << -1 << endl;
    return;
  }

  cout << op << endl;
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
