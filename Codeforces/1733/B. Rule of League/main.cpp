// ----------------------------------------------------------------------------
// Problem : B. Rule of League
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
    int n, x, y;
    cin >> n >> x >> y;

    // we need one of them zero and the other divides (n - 1)
    if (x == 0 && y == 0 || x != 0 && y != 0 || (n - 1) % max(x, y) != 0) {
      cout << -1 << endl;
      continue;
    }

    x = max(x, y); // non-zero

    n--;
    int c = 1;
    bool flag = true;
    while (n) {
      int a = x;
      while (a--)
        cout << c << " ";
      n -= x;
      c += x + flag;
      flag = false;
    }

    cout << endl;
  }
  return 0;
}
