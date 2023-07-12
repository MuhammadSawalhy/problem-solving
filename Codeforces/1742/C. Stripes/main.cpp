// Date: 13-10-2022
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#endif

void solve() {
  vector<vector<char>> m(8, vector<char>(8));

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> m[i][j];
    }
  }

  char c = 'R';
  bool ok;
  for (int i = 0; i < 8; i++) {
    ok = true;
    for (int j = 0; j < 8; j++) {
      if (m[i][j] != c) {
        ok = false;
        break;
      }
    }
    if (ok) {
      break;
    }
  }

  if (ok) {
    cout << "R" << endl;
  } else {
    cout << "B" << endl;
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
