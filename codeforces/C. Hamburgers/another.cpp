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
  string recipe;
  cin >> recipe;
  int rb = 0, rs = 0, rc = 0;
  for (char ch : recipe) {
    if (ch == 'B')
      rb++;
    if (ch == 'S')
      rs++;
    if (ch == 'C')
      rc++;
  }

  int b, s, c;
  cin >> b >> s >> c;
  int pb, ps, pc;
  cin >> pb >> ps >> pc;

  int r;
  cin >> r;

  r += b * pb + s * ps + c * pc;
  int p = rb * pb + rs * ps + rc * pc;

  debug(p, r);

  int n = r / p;
  cout << n << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
