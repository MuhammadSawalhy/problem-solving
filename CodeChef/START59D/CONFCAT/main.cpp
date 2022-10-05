// Date: 05-10-22
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

void solve() {
  int n;
  cin >> n;
  int a[n];

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int j = max_element(a, a + n) - a;
  if (j == 0) {
    cout << -1 << endl;
    return;
  }

  cout << j << endl;
  for (int i = 0; i < j; i++)
    cout << a[i] << " ";
  cout << endl;

  cout << n - j << endl;
  for (int i = j; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
