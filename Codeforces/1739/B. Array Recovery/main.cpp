// Date: 29-09-22
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
  vector<int> b(n);
  for (auto &i : b)
    cin >> i;
  vector<int> a(n);
  a[0] = b[0];
  debug(b);
  for (int i = 1; i < n; i++) {
    int x = b[i] + a[i - 1];
    int y = a[i - 1] - b[i];
    debug(i, x, y);
    if (x < 0 && y < 0 || (y >= 0 && x >= 0 && x != y)) {
      cout << -1 << endl;
      return;
    }

    a[i] = max(x, y);
  }

  for (auto i : a)
    cout << i << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--) {
    solve();
  }
  return 0;
}
