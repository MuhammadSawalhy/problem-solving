// Date: 16-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

void solve() {
  int n, m;
  cin >> n >> m;

  int fr[n][26];
  memset(fr, 0, sizeof fr);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      fr[i][c - 'a']++;
    }
  }

  bool valid[26] = {};
  memset(valid, 1, sizeof valid);
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < 26; k++) {
      if (fr[i][k] == 0) {
        valid[k] = false;
      }
    }
  }

  for (int k = 0; k < 26; k++) {
    if (valid[k]) {
      cout << "Yes" << endl;
      return;
    }
  }

  cout << "No" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  solve();

  return 0;
}
