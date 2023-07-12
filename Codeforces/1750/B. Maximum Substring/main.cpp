// Date: 06-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

void solve() {
  vector<pair<int, int>> a;
  int n;
  cin >> n;
  string s;
  cin >> s;
  ll ans = 0;

  int ones = 0, zeros = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') ones++;
    else
      zeros++;
    if (a.empty() || a.back().first != s[i] - '0') {
      a.push_back({s[i] - '0', 1});
    } else {
      a.back().second++;
    }
  }

  ans = (ll) zeros * ones;

  for (int i = 0; i < (int) a.size(); i++) {
    ans = max(ans, (ll) a[i].second * a[i].second);
  }

  cout << ans << endl;
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
