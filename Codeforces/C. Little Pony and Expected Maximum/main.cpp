//============================================================================
// Problem     : C. Little Pony and Expected Maximum
// Author      : Muahmmad Assawalhy
// Date        : 01-09-22
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
  int m, n;
  cin >> m >> n;
  double ans = 0;
  for (int i = 1; i <= m; i++) {
    ans += i * (pow((i / (double)m), n) - pow(((i - 1) / (double)m), n));
  }
  cout << fixed << setprecision(15) << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
