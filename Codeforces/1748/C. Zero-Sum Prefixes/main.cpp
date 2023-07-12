// Date: 13-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

void solve() {
  int n;
  cin >> n;
  int a[n];
  long long ps[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ps[i] = (long long) a[i] + (i > 0 ? ps[i - 1] : 0);
  }

  long long ans = 0;

  debug(ITR, a, a + n);

  int l = 0, r = 0;
  while (l < n && a[l] != 0) {
    if (ps[l] == 0)
      ans++;
    l++;
  }
  r = l;


  while (l < n) {
    map<long long, int> fr;
    fr[ps[r]]++;
    r++;
    while (r < n && a[r] != 0) {
      fr[ps[r]]++;
      r++;
    }

    debug(l, r);
    debug(fr);

    int m = 0;
    for (auto [k, v]: fr) {
      m = max(v, m);
    }

    ans += m;

    l = r;
  }

  cout << ans << endl;
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
