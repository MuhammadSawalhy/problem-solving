// Date: 18-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

void solve() {
  ll n, m;
  cin >> n >> m;

  int two = 0, five = 0;
  ll nn = n;
  while (nn % 2 == 0) {
    nn /= 2;
    two++;
  }
  nn = n;
  while (nn % 5 == 0) {
    nn /= 5;
    five++;
  }

  ll mm = 1;
  while (five < two && mm * 5 <= m) {
    mm *= 5;
    five++;
  }
  while (two < five && mm * 2 <= m) {
    mm *= 2;
    two++;
  }

  while (mm * 10 <= m) {
    mm *= 10;
  }


  ll x = m / mm * mm;
  debug(m, mm);
  debug(x);

  cout << 1LL * n * x << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
