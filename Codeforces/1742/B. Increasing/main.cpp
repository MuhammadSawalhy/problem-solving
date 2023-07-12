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
  vector<int> a(n);

  map<int, bool> vis;
  bool ok = true;
  for (auto &i : a) {
    cin >> i;

    if (vis[i]) {
      ok = false;
    }

    vis[i] = true;
  }

  if (ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
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
