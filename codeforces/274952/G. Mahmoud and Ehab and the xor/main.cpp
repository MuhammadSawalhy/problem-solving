// ----------------------------------------------------------------------------
// Problem : G. Mahmoud and Ehab and the xor
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
  int n, x;
  cin >> n >> x;

  // solution idea:
  // - handle special cases of n == 1 and n == 2
  // - when n > 2 print incrementally all numbers starting from 0, but don't
  // print the last three numbers
  // - choose the last three numbers to satisfy the conditions

  if (n == 1) {
    cout << "YES" << endl;
    cout << x << endl;
    return 0;
  }

  if (n == 2) {
    if (x == 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      cout << 0 << " ";
      cout << x << endl;
    }
    return 0;
  }

  cout << "YES" << endl;

  int xx = 0;
  int counter = 0;
  for (int i = 0; i < n - 3; i++) {
    xx ^= counter;
    cout << counter++ << " ";
  }

  // we don't want (x ^ xx) to be zero because `a` will always equal `b`
  // so, chosoe the 3rd number from the end to get the desired situation
  int l = 0;
  while (true) {
    xx ^= l;
    l = counter++;
    xx ^= l;
    if ((x ^ xx) != 0)
      break;
  }

  cout << l << " ";

  // choose the last 2 elements to hold the condition that xor of all elements equals `x`
  // ans also all nubmers are distinct
  int a = 0, b;
  while (true) {
    xx ^= a;
    a = counter++;
    xx ^= a;

    b = x ^ xx;
    if (b > l && b != a)
      break;
  }

  cout << a << " " << b << endl;
  return 0;
}
