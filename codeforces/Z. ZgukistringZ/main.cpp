// Date: 15-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

string a, b, c;
vector<ll> fra(200), frb(200), frc(200);

int calc(ll sum) {
  for (ll x = 0; x <= sum; x++) {
    bool ok = true;

    for (char ch = 'a'; ch <= 'z'; ch++) {
      if (x * frb[ch] + (sum - x) * frc[ch] > fra[ch]) {
        ok = false;
        break;
      }
    }

    if (ok) {
      return x;
    }
  }

  return -1;
}

void solve() {
  cin >> a >> b >> c;

  for (char c : a) {
    fra[c]++;
  }
  for (char c : b) {
    frb[c]++;
  }
  for (char c : c) {
    frc[c]++;
  }

  ll x = 0;
  ll s = 0, e = 1e5 + 1;
  while (e - s > 1) {
    int mid = (s + e) >> 1;
    int xx = calc(mid);
    if (~xx) {
      s = mid;
      x = xx;
    } else {
      e = mid;
    }
  }

  assert(x >= 0 && s >= x);

  string t;
  for (int i = x; i--;) {
    t += b;
    assert(t.size() <= a.size());
  }
  for (int i = s - x; i--;) {
    t += c;
    assert(t.size() <= a.size());
  }

  for (char ch = 'a'; ch <= 'z'; ch++) {
    for (ll i = fra[ch] - x * frb[ch] - (s - x) * frc[ch]; i--;)
      t += ch;
    assert(t.size() <= a.size());
  }

  cout << t << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  solve();

  return 0;
}
