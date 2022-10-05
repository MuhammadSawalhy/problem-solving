// Date: 05-10-22
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

void solve() {
  int x, y, z;
  cin >> x >> y >> z;
  if (x > y && x > z) {
    cout << "Setter" << endl;
  } else if (y > z) {
    cout << "Tester" << endl;
  } else {
    cout << "Editorialist" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
