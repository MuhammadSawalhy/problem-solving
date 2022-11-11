// Date: 16-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

void solve() {
  int n, q;
  cin >> n >> q;
  vector<long long> a(n + 1);

  for (int i = 1; i <= n; i++)
    cin >> a[i], a[i] += a[i - 1];

  while (q--) {
    int l, r;
    cin >> l >> r;
    long long sum = a[r] - a[l - 1];
    cout << sum << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  solve();

  return 0;
}
