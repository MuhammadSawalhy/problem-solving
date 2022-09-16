// ----------------------------------------------------------------------------
// Problem : C. New Year and Old Property
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

#define pop_cnt(x) (__builtin_popcountll(x))
#define LSB(x) (__builtin_ffsll(x) - 1)
#define MSB(x) (64 - __builtin_clzll(x) - 1)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ull a, b;
  cin >> a >> b;
  ull ans = 0;
  for (int i = MSB(b); i >= 1; i--) {
    for (int j = i - 1; j >= 0; j--) {
      ull y = (1LL << (i + 1)) - 1 - (1LL << j);
      if (y >= a && y <= b)
        ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
