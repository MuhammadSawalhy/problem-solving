// Date: 24-10-2022
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
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);


  for (int i = 1; i < n; i++) {
    if (a[i - 1] + 1 == a[i]) {
      cout << 2 << endl;
      return;
    }
  }

  cout << 1 << endl;
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
