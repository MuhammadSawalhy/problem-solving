// ----------------------------------------------------------------------------
// Problem : A. Mainak and Array
// Author  : Muahmmad Assawalhy
// Date    : 06-09-22
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
  cin.tie(NULL);
  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--) {
    int n;
    cin >> n;
    vi a(n);
    for (int &i : a)
      cin >> i;
    int ans = INT_MIN;

    for (int i = 0; i < n; i++) {
      ans = max(ans, a[(n - 1 + i) % n] - a[i]);
    }

    if (n > 1) {
      int m;

      m = INT_MIN;
      for (int i = 1; i < n; i++) {
        m = max(m, a[i]);
      }
      ans = max(ans, m - a[0]);

      m = INT_MAX;
      for (int i = 0; i < n - 1; i++) {
        m = min(m, a[i]);
      }

      ans = max(ans, a[n - 1] - m);
    }

    cout << ans << endl;
  }
  return 0;
}
