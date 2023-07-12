// Date: 17-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

void solve() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  vector<ll> afactors;
  for (int i = 1;; i++) {
    if (i * i > a) break;
    if (a % i == 0) {
      afactors.push_back(i);
      afactors.push_back(a / i);
    }
  }

  vector<ll> bfactors;
  for (int i = 1;; i++) {
    if (i * i > b) break;
    if (b % i == 0) {
      bfactors.push_back(i);
      bfactors.push_back(b / i);
    }
  }

  for (auto af : afactors) {
    for (auto bf : bfactors) {
      ll xshare = af * bf;
      ll yshare = a * b / af / bf;
      // greadily choose the biggest possible value
      ll x = c / xshare * xshare;
      ll y = d / yshare * yshare;
      if (x > a && y > b) {
        cout << x << " " << y << endl;
        return;
      }
    }
  }

  cout << "-1 -1" << endl;
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
