// ----------------------------------------------------------------------------
// Problem : A. Random Mood
// Author  : Muahmmad Assawalhy
// Date    : 07-09-22
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

double prob(int n, double p) {
  if (n == 0)
    return 0;
  double pp = prob(n / 2, p);
  pp = pp * (1 - pp) + (1 - pp) * pp;
  if (n & 1)
    pp = p * (1 - pp) + (1 - p) * pp;
  return pp;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  double p;
  cin >> n >> p;
  double inip = p;
  double happy = 1;
  cout << fixed << setprecision(15) << 1 - prob(n, p) << endl;
  return 0;
}
