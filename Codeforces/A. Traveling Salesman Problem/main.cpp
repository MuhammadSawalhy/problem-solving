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
  int n;
  cin >> n;

  int x = 0, xx = 0, y = 0, yy = 0;
  while (n--) {
    int a, b;
    cin >> a >> b;
    if (b == 0) {
      if (a < 0) {
        xx = max(-a, xx);
      } else {
        x = max(a, x);
      }
    } else {
      if (b < 0) {
        yy = max(-b, yy);
      } else {
        y = max(b, y);
      }
    }
  }

  cout << 2 * (x + xx + y + yy) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_cases;
  cin >> t_cases;
  while (t_cases--)
    solve();
  return 0;
}
