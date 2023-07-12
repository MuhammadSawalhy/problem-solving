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

  int s, h, g, e;
  int ss, hh, gg, ee;
  string f;
  for (int i = 0; i < n; i++) {
    cin >> f;
    for (int j = 0; j < n; j++) {
      char c = f[j];
      if (c == 'S')
        s = i;
      if (c == 'H')
        h = i;
      if (c == 'E')
        e = i;
      if (c == 'G')
        g = i;
    }
  }

  int he = e;
  if (he < h)
    swap(he, h);

  int se = e;
  if (se < s)
    swap(se, s);

  int ok = true;

  if (g >= h && g <= he)
    ok = false;

  else if (g >= s && g <= se)
    ok = false;

  if (ok)
    cout << "Scooby-Dooby-Doo!" << endl;
  else
    cout << "Ruh-roh--RAGGY!!!" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
