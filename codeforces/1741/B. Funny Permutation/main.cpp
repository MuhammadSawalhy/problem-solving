// Date: 11-10-2022
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
  if (n == 3) {
    cout << -1 << endl;
    return;
  }

  cout << n << " " << n - 1 << " ";

  for (int i = 1; i <= n - 2; i++) {
    cout << i << " ";
  }
  cout << endl;
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
