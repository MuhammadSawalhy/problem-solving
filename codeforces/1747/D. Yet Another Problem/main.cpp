// Date: 04-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

void solve() {
  int n, q;
  cin >> n >> q;

  int a[n + 1];
  int xr[n + 1];
  ll ps[n + 1];
  map<int, vector<int>> f[2];
  xr[0] = ps[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ps[i] = ps[i - 1] + a[i];
    xr[i] = xr[i - 1] ^ a[i];
    f[i & 1][xr[i]].push_back(i);
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    if (xr[r] != xr[l - 1]) {// impossible
      cout << -1 << endl;
    } else if (ps[r] == ps[l - 1]) {// all are zeros
      cout << 0 << endl;
    } else if ((r - l + 1) % 2) {// odd range
      cout << 1 << endl;
    } else if (a[r] == 0 || a[l] == 0) {// even range with zero at the edge
      cout << 1 << endl;
    } else {// even range, may be possible
      // opposite polarity with the same xor
      // so we can parition the even range into two odd ranges
      auto &w = f[~r & 1][xr[r]];
      auto it = lower_bound(all(w), l + 1);
      if (it != w.end() && *it < r) {
        cout << 2 << endl;
      } else {
        cout << -1 << endl;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  solve();

  return 0;
}
