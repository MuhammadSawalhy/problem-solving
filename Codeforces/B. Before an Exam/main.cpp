// Date: 23-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

void solve() {
  int n, s;
  cin >> n >> s;

  int mx[n];
  int mn[n];
  int sum = 0;
  int ans[n];
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    sum += a;
    mn[i] = a;
    mx[i] = b;
    ans[i] = a;
  }

  if (sum > s) {
    cout << "NO" << endl;
    return;
  }

  for (int i = 0; sum < s && i < n; i++) {
    int d = min(s - sum, mx[i] - mn[i]);
    sum += d;
    ans[i] += d;
  }

  if (sum != s) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n-1];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  solve();

  return 0;
}
