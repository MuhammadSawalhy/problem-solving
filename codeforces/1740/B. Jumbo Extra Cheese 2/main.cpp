// Date: 29-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> slices(n);
  for (int i = 0; i < n; i++) {
    cin >> slices[i].first >> slices[i].second;
    if (slices[i].first < slices[i].second) {
      swap(slices[i].first, slices[i].second);
    }
  }

  sort(all(slices));

  ll a = 0, b = 0;
  a += slices[0].first;
  b += slices[0].second;
  for (int i = 1; i < n; i++) {
    a += slices[i].first - slices[i - 1].first;
    b += slices[i].second;
  }

  cout << a * 2 + b * 2 << endl;
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
