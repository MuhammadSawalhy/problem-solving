// Date: 12-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

void solve() {
  int n;
  string s;
  cin >> n >> s;

  long long ans = 0;

  int fr[10] = {};

  auto valid = [&]() {
    int distinct = 0;
    for (int i = 0; i < 10; i++) {
      if (fr[i]) distinct++;
    }
    for (int i = 0; i < 10; i++)
      if (fr[i] > distinct)
        return false;
    return true;
  };

  debug(s);
  for (int i = 0; i < n; i++) {
    memset(fr, 0, sizeof fr);
    for (int j = i; j >= max(0, i - 100); j--) {
      fr[s[j] - '0']++;
      ans += valid();
    }
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
