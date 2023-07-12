// ----------------------------------------------------------------------------
// Problem : D. Preparing Olympiad
// Author  : Muahmmad Assawalhy
// Date    : 03-09-22
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
  int n, l, r, x;
  cin >> n >> l >> r >> x;
  vi c(n);
  for (int &i : c)
    cin >> i;

  int ans = 0;

  for (int i = 0; i < 1 << n; i++) {
    if (__builtin_popcountll(i) < 2)
      continue;
    int s = 0, mn = INT_MAX, mx = 0;
    for (int j = 0; j < n; j++) {
      if (i & 1 << j)
        s += c[j], mn = min(mn, c[j]), mx = max(mx, c[j]);
    }

    if (s >= l && s <= r && mx - mn >= x)
      ans++;
  }

  cout << ans << endl;
  return 0;
}
