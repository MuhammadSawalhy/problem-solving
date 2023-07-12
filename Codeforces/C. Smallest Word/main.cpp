// Date: 15-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

void solve() {
  string s;
  cin >> s;
  vector<bool> flips(s.size());

  bool a = false;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == 'a') {
      if (!a && i > 0)
        flips[i - 1] = true;
      a = true;
    } else if (s[i] == 'b') {
      if (a && i > 0)
        flips[i - 1] = true;
      a = false;
    }
  }

  flips[(int)s.size() - 1] = a;

  for (int i = 0; i < (int)s.size(); i++) {
    cout << flips[i] << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  solve();

  return 0;
}
