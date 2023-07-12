// Date: 18-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

void solve() {
  ll l, r, x, a, b;
  cin >> l >> r >> x >> a >> b;

  if (a == b) {
    cout << 0 << endl;
  } else if (abs(b - a) >= x) {
    cout << 1 << endl;
  } else if (abs(a - l) >= x && abs(b - l) >= x || abs(a - r) >= x && abs(b - r) >= x) {
    // go to either of the edges then go to it
    cout << 2 << endl;
  } else if ((abs(b - l) >= x || abs(b - r) >= x) && abs(l - r) >= x && (abs(a - l) >= x || abs(a - r) >= x)) {
    // go to both of the edges then go to it
    cout << 3 << endl;
  } else {
    cout << -1 << endl;
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
