// Date: 11-10-2022
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#endif

void solve() {
  string a, b;
  cin >> a >> b;
  char la = a[a.size() - 1], lb = b[b.size() - 1];
  if (la == lb) {
    if (la == 'S') {
      cout << (a == b ? "=" : a.size() > b.size() ? "<" : ">") << endl;
    } else {
      cout << (a == b ? "=" : a.size() > b.size() ? ">" : "<") << endl;
    }
  } else {
    cout << (la < lb ? ">" : "<") << endl;
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
