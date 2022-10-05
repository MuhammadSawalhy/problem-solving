// ----------------------------------------------------------------------------
// Problem : D1. Zero-One (Easy Version)
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
  cin.tie(NULL), cout.tie(NULL);
  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--) {
    ll n, x, y;
    cin >> n >> x >> y;
    string a, b;
    cin >> a >> b;
    int a1 = 0, b1 = 0;

    vi ind;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i])
        ind.push_back(i);
    }

    if (ind.size() & 1) {
      cout << -1 << endl;
      continue;
    }

    ll ans = 0;
    ll adj = 0, sep = 0;

    for (int i = 1; i < ind.size(); i++) {
      if (ind[i] == ind[i - 1] + 1) {
        ind[i] = -1;
        ind[i - 1] = -1;
        adj++;
        i++;
      }
    }

    int i = 0, j = ind.size() - 1;
    while (i < j) {
      while (i < ind.size() && ind[i] == -1)
        i++;
      while (j > i && ind[j] == -1)
        j--;

      if (i >= j)
        break;

      ind[i] = -1;
      ind[j] = -1;
      sep++;
    }

    if (adj == 1 && sep == 0) {
      // one pair adjacent pair
      cout << min(x, 2 * y) << endl;
    } else {
      cout << (sep + adj) * y << endl;
    }
  }
  return 0;
}
