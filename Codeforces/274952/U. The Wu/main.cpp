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

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> w(n);
  for (auto &i : w)
    cin >> i;
  unordered_map<string, int> S;                       // set item and frequency
  unordered_map<string, vector<pair<int, int>>> memo; // t and possible values
  for (int i; i < m; i++) {
    string ss;
    cin >> ss;
    S[ss]++;
  }

  while (q--) {
    string t;
    int k;
    cin >> t >> k;
    vector<pair<int, int>> values;
    if (memo.find(t) != memo.end()) {
      values = memo[t];
    } else {
      for (auto [s, fr] : S) {
        int v = 0;
        for (int i = 0; i < n; i++) {
          if (s[i] == t[i])
            v += w[i];
        }
        if (v <= 100)
          values.push_back({v, fr});
      }
      memo[t] = values;
    }

    int ans = 0;
    for (auto [v, fr] : values)
      ans += v <= k ? fr : 0;
    cout << ans << endl;
  }

  return 0;
}
