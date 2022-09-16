// ----------------------------------------------------------------------------
// Problem : B. Best Permutation
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

    if (n == 4) {
      cout << "2 1 3 4" << endl;
      continue;
    }

    if (n == 5) {
      cout << "1 2 3 4 5" << endl;
      continue;
    }

    int x = 0;
    for (int i = 4; i <= n - 2; i++) {
      if (x < i)
        x += i;
      else
        x = 0;
      cout << i << ' ';
    }

    if (x == 0) {
      cout << "1 2 3 ";
    } else {
      cout << "3 2 1 ";
    }

    cout << n - 1 << " " << n << endl;
  }
  return 0;
}
