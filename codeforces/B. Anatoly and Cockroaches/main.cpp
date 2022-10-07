// Date: 06-10-22
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
  int n;
  string l;
  cin >> n >> l;

  int r = 0, b = 0;
  bool red = true;

  for (int i = 0; i < n; i++) {
    if (l[i] == (red ? 'b' : 'r')) {
      if (red)
        b++;
      else
        r++;
    }
    red = !red;
  }

  int ans1;
  ans1 = min(r, b) + max(r, b) - min(r, b);

  red = r = b = 0;
  for (int i = 0; i < n; i++) {
    if (l[i] == (red ? 'b' : 'r')) {
      if (red)
        b++;
      else
        r++;
    }
    red = !red;
  }

  int ans2;
  ans2 = min(r, b) + max(r, b) - min(r, b);

  cout << min(ans1, ans2) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  solve();
  return 0;
}
