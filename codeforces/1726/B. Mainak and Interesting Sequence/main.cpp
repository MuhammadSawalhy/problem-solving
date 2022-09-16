// ----------------------------------------------------------------------------
// Problem : B. Mainak and Interesting Sequence
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
    int n, m;
    cin >> n >> m;

    if (m < n) {
      cout << "NO" << endl;
      continue;
    }

    vi ans(n, 1);
    m -= n;

    if (m) {
      if (n & 1) {
        ans[0] += m;
      } else {
        if (m & 1) {
          cout << "NO" << endl;
          continue;
        }
        ans[0] += m / 2;
        ans[1] += m - m / 2;
      }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
      cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
