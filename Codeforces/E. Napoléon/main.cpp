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

int n;

void solve() {
  int xc, yc, xt, yt;
  cin >> xc >> yc >> xt >> yt;

  int c = yc - xc;
  int cc = yt + xt;

  if (cc - c < 0) {
    c = yc + xc;
    cc = yt - xt;
  }

  if (abs(cc - c) & 1) {
    cout << "can't reach!" << endl;
  } else {
    int x = abs(cc - c) >> 1;
    cout << abs(xc - x) + abs(xt - x) << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_cases;
  cin >> t_cases;
  cin >> n;
  while (t_cases--)
    solve();
  return 0;
}
