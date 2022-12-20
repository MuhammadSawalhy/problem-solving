// Date: 25-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef LOCAL
#include "debug.hpp"
#endif

void solve() {
  int n;
  cin >> n;

  if (n & 1) {
    for (int i = 0; i < n; i++) {
      cout << 1 << " ";
    }
    cout << endl;
    return;
  }

  for (int i = 0; i < n - 2; i++) {
    cout << 2 << " ";
  }
  cout << 1 << " " << 3 << endl;
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
