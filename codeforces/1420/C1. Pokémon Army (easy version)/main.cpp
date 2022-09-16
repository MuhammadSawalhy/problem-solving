// ----------------------------------------------------------------------------
// Problem : C1. Pokémon Army (easy version)
// Author  : Muahmmad Assawalhy
// Date    : 12-09-22
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
    int n, q;
    cin >> n >> q;
    assert(q == 0);
    vi a(n);
    for (int &i : a)
      cin >> i;

    ull ans = 0;
    for (int i = 0; i < n; i++)
      ans += max(0, a[i] - (i == n - 1 ? 0 : a[i + 1]));
    cout << ans << endl;
  }
  return 0;
}
