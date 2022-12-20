// Date: 30-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

void solve() {
  int n;
  cin >> n;
  ll a[n];
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt += (a[i] & 1);
  }

  if (cnt == 0) {
    cout << "NO" << endl;
    return;
  }

  cout << (cnt & 1 ? "NO" : "YES") << endl;
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
