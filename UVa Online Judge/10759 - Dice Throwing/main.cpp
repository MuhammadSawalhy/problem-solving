// ----------------------------------------------------------------------------
// Problem : 10759 - Dice Throwing
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

ull memo[25][150];

ull count(int n, int x) {
  if (n == 0 && x > 0)
    return 0;

  if (x <= 0) {
    ull c = 1;
    while (n--) {
      c *= 6;
    }
    return c;
  }

  ull &c = memo[n][x];
  if (c != ULONG_LONG_MAX)
    return c;

  c = 0;
  for (int i = 1; i <= 6; i++) {
    c += count(n - 1, x - i);
  }

  return c;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x;
  while (true) {
    cin >> n >> x;
    if (n == 0)
      break;
    memset(memo, -1, sizeof memo);

    // debug(count(1, 3));
    // continue;
    ull c = count(n, x);
    ull a = 1;
    while (n--) {
      a *= 6;
    }
    debug(c, a);

    if (c == 0) {
      cout << 0 << endl;
      continue;
    }

    if (c == a) {
      cout << 1 << endl;
      continue;
    }

    ull g = __gcd(a, c);

    cout << c / g << "/" << a / g << endl;
  }
  return 0;
}
