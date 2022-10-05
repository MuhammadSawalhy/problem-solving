// Date: 23-09-22
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
  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cout << 1 << " ";
      for (int j = 2; j <= i; j++) {
        cout << (j == i) << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
