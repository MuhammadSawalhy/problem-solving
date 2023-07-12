// Date: 05-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int n;
  cin >> n;
  vector<pair<int, int>> a;
  int uptip;
  ll ans = 0;

  int x;
  cin >> x;
  int prev = x;
  a.push_back({x, 1});

  for (int i = 1; i < n; i++) {
    cin >> x;

    while (a.size() && a.back().first < x) {
      ans += a.back().second;
      a.pop_back();
    }

    debug(1, ans);

    if (a.size() && a.back().first == x) {
      ans += a.back().second;
      if (a.size() > 1)
        ans += 1;
      a.back().second += 1;
    } else {
      ans += !a.empty();
      a.push_back({x, 1});
    }

    prev = x;
    debug(2, ans);
    debug(a);
  }

  cout << ans << endl;

  return 0;
}
