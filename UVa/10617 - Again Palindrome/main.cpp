//============================================================================
// Problem     : 10617 - Again Palindrome
// Author      : Muahmmad Assawalhy
// Date        : 03-09-22
//============================================================================

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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()

string s;
int memo[60][60];

int palin(int i, int j) {
  if (i == j)
    return 1;
  // (i + 1, j - 1) will result in i > j at some point (after i == j)
  if (i > j)
    return 0;

  int &p = memo[i][j];
  if (p != -1)
    return p;

  p = 0;

  if (s[i] == s[j])
    p += palin(i + 1, j - 1) + 1;

  p += palin(i + 1, j);
  p += palin(i, j - 1);
  p -= palin(i + 1, j - 1); // remove duplications

  return p;
}

void solve() {
  cin >> s;
  memset(memo, -1, sizeof memo);
  cout << palin(0, s.size() - 1) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--)
    solve();
  return 0;
}
