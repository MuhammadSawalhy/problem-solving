// Date: 21-11-2022
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

  for (int i = 25; ~i; i--) {
    if (s.find('a' + i) != string::npos) {
      cout << i + 1 << endl;
      return;
    }
  }
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
