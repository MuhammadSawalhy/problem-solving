// Date: 25-09-22
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
  int n, c;
  cin >> n >> c;
  vector<int> a(101);
  for (int i = 0; i < n; i++) {
    int aa;
    cin >> aa;
    a[aa]++;
  }

  int ans = 0;
  for (int i = 0; i <= 100; i++) {
    ans += min(c, a[i]);
  }

  cout << ans << endl;
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
