// Date: 22-09-22
#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  int s[n];
  for (int i = 0; i < n; i++) {
    s[i] = 0;
    for (int j = n; j--;) {
      bool b;
      cin >> b;
      s[i] |= b << j;
    }
  }

  int m = 0;
  int ans[20];
  int tempans[20];
  for (int mask = 1; mask < (1 << n); mask++) {
    if (__builtin_popcount(mask) <= m)
      continue;

    int k = 0;
    bool ok = true;
    for (int j = 0; j < n; j++) {
      if (mask & (1 << j)) {
        tempans[k++] = n - 1 - j; // reverse
        if ((s[n - 1 - j] & mask) != mask) {
          ok = false;
          break;
        }
      }
    }

    if (ok) {
      m = k;
      for (int i = 0; i < m; i++) {
        ans[i] = tempans[i];
      }
    }
  }

  cout << m << endl;
  for (int i = 0; i < m; i++)
    cout << ans[i] + 1 << " ";
  cout << endl;
  return 0;
}
