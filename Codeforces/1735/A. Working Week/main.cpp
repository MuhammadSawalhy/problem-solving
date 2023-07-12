// Date: 02-10-22
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

void binary_search() {
  int n;
  cin >> n;
  int s = 0, e = 1e9;

  auto valid = [&](int mn) { return (1 + (mn + 1) + (2 * mn + 1) <= n - 3); };

  while (s < e) {
    int mid = (s + e + 1) >> 1;
    if (valid(mid)) {
      s = mid;
    } else {
      e = mid - 1;
    }
  }

  cout << s << endl;
}

void solve() {
  int n;
  cin >> n;
  cout << n / 3 - 2 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--) {
    // binary_search();
    solve();
  }
  return 0;
}
