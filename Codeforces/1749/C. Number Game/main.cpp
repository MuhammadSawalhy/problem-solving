// Date: 21-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  auto valid = [&](int k) {
    if (k > n)
      return false;
    vector<int> b(a, a + n);

    for (int i = 1; i <= k; i++) {
      // -> greedy steps
      // Alice removes the maximum that he can remove
      // Bob adds to the minimum

      int j = -1;
      int max = 0;

      for (int l = 0; l < (int)b.size(); l++) {
        if (b[l] <= k - i + 1 && b[l] > max) {
          max = b[l];
          j = l;
        }
      }

      if (~j) {
        b.erase(b.begin() + j);
      } else {
        return false;
      }

      if (b.size()) {
        auto it = min_element(b.begin(), b.end());
        *it += k - i + 1;
      }
    }

    return true;
  };

  int s = 0, e = 200;
  while (e - s > 1) {
    int mid = (s + e) >> 1;

    if (valid(mid)) {
      s = mid;
    } else {
      e = mid;
    }
  }

  cout << s << endl;
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
