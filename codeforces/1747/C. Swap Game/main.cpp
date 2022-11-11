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
  int n;
  cin >> n;
  int m = INT_MAX;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m = min(m, a[i]);
  }

  if (m == a[0]) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;
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
