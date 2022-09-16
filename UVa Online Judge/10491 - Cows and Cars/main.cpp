//============================================================================
// Problem     : 10491 - Cows and Cars
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
  double cows, cars, show;
  while (cin >> cows >> cars >> show) {
    cout << fixed << setprecision(5)
         << (cows * (cars) / (cars + cows - show - 1) +
             cars * (cars - 1) / (cars + cows - show - 1)) /
                (cars + cows)
         << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
