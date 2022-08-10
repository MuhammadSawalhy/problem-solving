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

#define int ll
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()
#define sum(v) accumulate(all(v), 0)

void solve() {
  int a, k;
  cin >> a >> k;

  vi ad;

  while (a) {
    ad.push_back(a % 10);
    a /= 10;
  }

  auto i = sz(ad) - 1;
  while (i > 0) {
    int imax = i;

    for (int j = i - 1; j >= max((int)0, i - k); j--) {
      if (ad[j] > ad[imax])
        imax = j;
    }

    if (i == imax) {
      i--;
    } else {
      k -= i - imax;
      int m = ad[imax];
      for (int j = imax; j < i; j++)
        ad[j] = ad[j + 1];
      ad[i] = m;
    }
  }

  for (int i = sz(ad) - 1; i >= 0; i--)
    std::cout << ad[i];

  std::cout << std::endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
