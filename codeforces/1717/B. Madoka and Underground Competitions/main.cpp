//============================================================================
// Problem     : B. Madoka and Underground Competitions
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

int n, k, r, c;
vector<string> ans;

void generate(int i, int j) {
  debug(i, j, n,  k, r , c, ans);
  for (int a = 0; a < k; a++) {
    for (int b = 0; b < k; b++) {
      char cell = '.';
      if (a == b && a != c && a != r)
        cell = 'X';
      if (a == r && b == c)
        cell = 'X';
      if (a == c && b == r)
        cell = 'X';
      ans[i + a] += cell;
    }
  }
}

void solve() {
  cin >> n >> k >> r >> c;
  r--, c--;
  r = r % k;
  c = c % k;
  ans.clear();
  ans.resize(n);

  for (int i = 0; i < n; i += k) {
    for (int j = 0; j < n; j += k) {
      generate(i, j);
    }
  }

  for (string &s : ans)
    cout << s << endl;
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
