// Date: 27-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  long long s[n + 1];
  s[0] = 0;

  for (int i = 1; i <= n; i++) {
    s[i] += a[i - 1];
  }

  map<int, bool> vis;

  vis[a[0]] = true;
  for (int i = 1; i < n; i++) {
    long long x = s[i];
    long long y = s[n] - a[i];
    if (x == y) {
      cout << "YES" << endl;
      return 0;
    }
    if () {
      cout << "YES" << endl;
      return 0;
    }
    vis[a[i]] = true;
  }

  cout << "NO" << endl;

  return 0;
}
