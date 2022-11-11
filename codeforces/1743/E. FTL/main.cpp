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

  ll p1, t1;
  ll p2, t2;
  ll h, s;
  cin >> p1 >> t1;
  cin >> p2 >> t2;
  cin >> h >> s;

  ll ans = 1e13;
  // loop over possible double shootings of both lasers
  for (ll z = 0; z <= (h + (p1 + p2 - s) - 1) / (p1 + p2 - s); z++) {
    // loop over possible shootings of the first laser
    for (ll x = 0;
         x <= max(0LL, (h - z * (p1 + p2 - s) + (p1 - s) - 1) / (p1 - s));
         x++) {
      // rest of the durability
      ll H = max(0LL, h - s * (p1 + p2 - s) - x * (p1 - s));
      // number of shootings needed of the second laser
      ll y = (H + p2 - s - 1) / (p2 - s);
      ll t = x * t1 + y * t2;
      // we need to add the min difference


      ans = min(t, ans);
    }
  }

  cout << ans << endl;

  return 0;
}
