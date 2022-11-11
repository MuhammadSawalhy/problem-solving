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
  int n, m, k;
  cin >> n >> m >> k;

  int a[k];
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }

  ll cnt = (ll)n * m - 2;
  int current = k;
  map<int, bool> vis;
  for (int i = 0; i < k; i++) {
    while (vis[current]) {
      current--;
      cnt++;
    }

    if (a[i] == current) {
      if (cnt < 2) {
        cout << "TIDAK" << endl;
        return;
      }

      current--;
      continue;
    }

    vis[a[i]] = true;
    cnt--;
  }

  cout << "YA" << endl;
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
