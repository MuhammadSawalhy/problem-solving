// Date: 12-10-2022
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#endif

void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int MAX = *max_element(a, a + n);
  vector<vector<int>> primes(MAX + 1);
  for (int i = 2; i <= MAX; i++) {
    if (primes[i].size()) continue;
    for (int j = i; j <= MAX; j += i) {
      primes[j].push_back(i);
    }
  }

  vector<int> fr(MAX + 1);
  for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < 1 << primes[a[i]].size(); mask++) {
      int f = 1;
      for (int j = 0; j < primes[a[i]].size(); j++) {
        if (~mask & (1 << j)) continue;
        f *= primes[a[i]][j];
      }
      fr[f]++;
    }
  }

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      ans += n - 1;
      continue;
    }
    long long cop = 0;
    for (int mask = 0; mask < 1 << primes[a[i]].size(); mask++) {
      int f = 1;
      int cnt = 0;
      for (int j = 0; j < primes[a[i]].size(); j++) {
        if (~mask & (1 << j)) continue;
        cnt++;
        f *= primes[a[i]][j];
      }
      cop += ((cnt & 1) ? -1 : 1) * fr[f];
    }
    ans += cop;
  }

  cout << ans / 2 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  solve();

  return 0;
}
