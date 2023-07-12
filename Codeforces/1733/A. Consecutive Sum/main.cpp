// ----------------------------------------------------------------------------
// Problem : A. Consecutive Sum
// Author  : Muahmmad Assawalhy
// Date    : 19-09-22
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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> a[i], s[i] = a[i] + s[i - 1];
    ll ans = INT_MIN;
    for (int i = k; i <= n; i++) {
      ll v = s[i] - s[i - k];
      for (int j = i - k + 1; j <= i; j++) {
        ll m = a[j];
        for (int x = j + k; x <= n; x += k) {
          m = max(m, a[x]);
        }
        for (int x = j - k; x >= 1; x -= k) {
          m = max(m, a[x]);
        }
        v += m - a[j];
        debug(m, a[j], j);
      }
      debug(v);
      ans = max(ans, v);
    }

    debug(ans);
    cout << ans << endl;
  }
  return 0;
}
