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
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int ok = false;
      for (int k = 0; k < n; k++) {
        for (int l = 0; l < m; l++) {
          if (abs((i - k) * (j - l)) == 2) {
            ok = true;
          }
        }
      }

      if (!ok) {
        cout << i + 1 << " " << j + 1 << endl;
        return;
      }
    }
  }

  cout << "1 1" << endl;
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
