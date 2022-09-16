// ----------------------------------------------------------------------------
// Problem : B. Fedor and New Game
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
  int n, m, k;
  cin >> n >> m >> k;
  vi p(m);
  for (auto &i : p)
    cin >> i;
  int me;
  cin >> me;
  int ans = 0;
  for (int i = 0; i < m; i++)
    ans += __builtin_popcountll((p[i] | me) - (p[i] & me)) <= k;
  cout << ans << endl;
  return 0;
}
