// ----------------------------------------------------------------------------
// Problem : H. Short Program
// Author  : Muahmmad Assawalhy
// Date    : 04-09-22
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
  int n;
  cin >> n;

  vector<string> op(n);
  vector<int> num(n);

  for (int i = 0; i < n; i++) {
    cin >> op[i];
    cin >> num[i];
  }

  int xr = 0, nd = (1 << 10) - 1, r = 0;
  for (int i = 0; i < 10; i++) {
    int x = 1 << i;
    int y = 0;

    for (int j = 0; j < n; j++) {
      if (op[j] == "^")
        x ^= num[j], y ^= num[j];
      if (op[j] == "|")
        x |= num[j], y |= num[j];
      if (op[j] == "&")
        x &= num[j], y &= num[j];
    }

    int xb = (x >> i) & 1;
    int yb = (y >> i) & 1;

    if (xb == 0 && yb == 1) {
      xr |= (1 << i);
    }

    if (xb == 0 && yb == 0) {
      nd &= ~(1 << i);
    }

    if (xb == 1 && yb == 1) {
      r |= 1 << i;
    }
  }

  cout << 3 << endl;
  cout << "| " << r << endl;
  cout << "& " << nd << endl;
  cout << "^ " << xr << endl;

  return 0;
}
