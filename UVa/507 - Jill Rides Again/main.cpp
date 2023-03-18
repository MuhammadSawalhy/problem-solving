// ----------------------------------------------------------------------------
// Problem : 507 - Jill Rides Again
// Author  : Muahmmad Assawalhy
// Date    : 20-09-22
// ----------------------------------------------------------------------------

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef unsigned long long ull;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t_cases = 1;
  cin >> t_cases;
  for (int t = 1; t <= t_cases; t++) {
    int r;
    cin >> r;
    vi a(r - 1);
    for (int &i : a)
      cin >> i;

    ll s = 0, e = 0, n = a[0];
    ll bs = s, be = e, best = n;
    for (int i = 1; i < (int)a.size(); i++) {
      // n = max(n + a[i], a[i])
      // best = max(best, n)
      if (n + a[i] < a[i]) {
        n = a[i];
        s = i;
      } else {
        n += a[i];
      }

      e = i;

      if (best < n || n == best && be - bs < e - s) {
        best = n;
        bs = s;
        be = e;
      }
    }

    if (best < 0) {
      cout << "Route " << t << " has no nice parts" << endl;
    } else {
      cout << "The nicest part of route " << t << " is between stops "
           << bs + 1 << " and " << be + 2 << endl;
    }
  }
  return 0;
}
