// Date: 13-10-2022
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
  int b[n];
  for (int i = 0; i < n; i++)
    cin >> a[i], b[i] = a[i];

  vector<bool> vis(n);
  vector<int> ans;

  while (true) {
    int i = max_element(a, a + n) - a;
    int max = a[i];
    if (max == 0) {
      break;
    }

    ans.push_back(i);
    vis[i] = true;
    for (int i = 0; i < n; i++) {
      a[i] &= ~max;
    }
  }

  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      ans.push_back(i);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << b[ans[i]] << " ";
  }
  cout << endl;
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
