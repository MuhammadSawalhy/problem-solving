// Date: 13-10-2022
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#endif

void solve() {
  int q;
  cin >> q;
  vector<long long> s(1000);
  vector<long long> t(1000);
  s['a'] = 1;
  t['a'] = 1;

  auto can = [&]() {
    for (char ch = 'b'; ch <= 'z'; ch++) {
      if (t[ch])
        return true;
    }
    if (s['a'] < t['a']) {
      for (char ch = 'b'; ch <= 'z'; ch++) {
        if (s[ch])
          return false;
      }
    }

    return s['a'] < t['a'];
  };

  while (q--) {
    int d, k;
    string x;
    cin >> d >> k >> x;
    for (auto c : x) {
      if (d == 1) {
        s[c] += k;
      } else {
        t[c] += k;
      }
    }
    cout << (can() ? "YES" : "NO") << endl;
  }
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
