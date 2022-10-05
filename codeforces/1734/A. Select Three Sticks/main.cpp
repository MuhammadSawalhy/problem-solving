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
    vector<int> a(n);

    for (auto &i : a)
      cin >> i;

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          vector<int> s({a[i], a[j], a[k]});
          sort(s.begin(), s.end());
          ans = min(ans, s[2] - s[0]);
        }
      }
    }

    cout << ans << endl;
  }
  return 0;
}
