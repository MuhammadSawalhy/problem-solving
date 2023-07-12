// Date: 05-11-2022
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

  int q, x;
  cin >> q >> x;

  // set of non-existing numbers in `a`
  set<int> s;
  for (int i = 0; i <= q; i++) {
    s.insert(i);
  }

  // next min number (m) where m === i mod x
  map<int, int> m;
  for (int i = 0; i < x; i++) {
    m[i] = i;
  }

  while (q--) {
    int y;
    cin >> y;
    int r = y % x;

    int nxt = m[r];
    m[r] += x;

    s.erase(nxt);

    cout << *s.begin() << endl;
  }

  return 0;
}
