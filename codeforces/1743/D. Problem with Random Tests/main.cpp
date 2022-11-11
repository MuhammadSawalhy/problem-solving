// Date: 19-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int n;
  string s;
  cin >> n >> s;

  if (s == string(n, '0'))
    return !bool(cout << 0 << endl);

  reverse(s.begin(), s.end());
  while (s.back() == '0')
    s.pop_back();
  reverse(s.begin(), s.end());

  if (s == string(s.size(), '1'))
    return !bool(cout << s << endl);

  int j = s.find('0');

  string ans = s;
  for (int i = 0; i < j; i++) { // shift
    string t = s;
    for (int k = 0; k < n - j; k++) { // OR
      t[j + k] |= s[i + k];
    }
    ans = max(ans, t);
  }

  cout << ans << endl;

  return 0;
}
