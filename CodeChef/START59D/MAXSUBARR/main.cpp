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
  int n, m;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  cin >> m;
  long long b[m];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  // 1. split the loop of B into two stripes
  // DONE: 1. split the stripe of A into two stripes
  // DONE: get the max of 0 and max of sums of the possible 4 combintions of
  // these stripes

  long long A = 0, maxA = 0;

  for (int i = 0; i < n; i++) {
    A += a[i];
    maxA = max(A, maxA);
  }

  A = 0;
  for (int i = n - 1; i >= 0; i--) {
    A += a[i];
    maxA = max(A, maxA);
  }

  long long maxB = 0;
  for (int i = 0; i < m; i++) {
    maxB += max(0LL, b[i]);
  }

  cout << maxA + maxB << endl;
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
