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
  long long n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  long long x = 0, y = 0;

  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      x += a[i] > a[j];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;
      y += a[i] > a[j];
    }

  cout << k * x + k * (k - 1) / 2 * y << endl;
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
