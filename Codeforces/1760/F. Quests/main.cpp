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
  ll n, c, d;
  cin >> n >> c >> d;
  ll a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a, a + n, greater<int>());

  int s = -1, e = d;

  auto valid = [&](int mid) {
    ll value = 0;
    int j = 0;
    for (int i = 1; i <= d; i++) {// days
      if (j < n)
        value += a[j];
      debug(j, value);
      j++;
      j %= (mid + 1);
    }
    debug(mid, value);
    return value >= c;
  };

  while (e - s > 1) {
    int mid = (s + e) >> 1;
    if (valid(mid)) {
      s = mid;
    } else {
      e = mid;
    }
  }


  if (s == d - 1) {
    cout << "Infinity" << endl;
  } else if (e == 0) {
    cout << "Impossible" << endl;
  } else {
    cout << s << endl;
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
