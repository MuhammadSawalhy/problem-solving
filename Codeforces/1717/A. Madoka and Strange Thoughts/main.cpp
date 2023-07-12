//============================================================================
// Problem     : A. Madoka and Strange Thoughts
// Author      : Muahmmad Assawalhy
// Date        : 02-09-22
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
typedef unsigned long ul;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()

void solve() {
  ll n;
  cin >> n;
  cout << n + 2 * (n / 2 + n / 3) << endl;
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
