// Date: 21-09-22
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
    vector<long long> ans;
    long long s = 0;
    long long x = 0;
    while (n--) {
      int a;
      cin >> a;
      s += a;
      x ^= a;
    }

    if (s & 1) {
      ans.push_back(1);
      s += 1;
      x ^= 1;
    }

    // x and y are even
    if (s != 2 * x) {
      long long y = 1LL << 50;
      if (ans.empty())
        ans.push_back(y);
      else
        ans[0] += y; // there exists 1 here
      s += y;
      x ^= y;
      ans.push_back(x - s / 2);
      ans.push_back(x - s / 2);
    }

    cout << ans.size() << endl;
    for (auto i : ans)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
