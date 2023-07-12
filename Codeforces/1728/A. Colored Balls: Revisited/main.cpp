// ----------------------------------------------------------------------------
// Problem : A. Colored Balls: Revisited
// Author  : Muahmmad Assawalhy
// Date    : 08-09-22
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
    vi c(n);
    for (int &i : c)
      cin >> i;

    int m = 0;
    for (int i = 1; i < n; i++) {
      if (c[i] > c[m])
        m = i;
    }

    cout << m + 1 << endl;
  }
  return 0;
}
