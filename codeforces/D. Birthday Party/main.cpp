// Date: 24-10-2022
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
  vector<tuple<char, int, int>> friends;
  for (int i = 0; i < n; i++) {
    char t;
    int s, e;
    cin >> t >> s >> e;
    friends.push_back(make_tuple(t, s, e));
  }

  int ans = 0;
  for (int d = 1; d <= 366; d++) {
    int m = 0, f = 0;
    for (int i = 0; i < n; i++) {
      char t;
      int s, e;
      tie(t, s, e) = friends[i];
      if (s > d || e < d)
        continue;
      if (t == 'F') {
        f++;
      } else {
        m++;
      }
    }
    ans = max(ans, min(m, f));
  }

  cout << ans * 2 << endl;

  return 0;
}
