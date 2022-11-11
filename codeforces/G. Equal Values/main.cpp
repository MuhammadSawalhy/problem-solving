// Date: 16-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> fr(101);
  int arr[101];
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    fr[a]++;
  }

  arr + 1;

  fr.push_back(5);
  fr.erase(fr.begin() + 2);

  while (q--) {
    int x;
    cin >> x;
    int ans = 0;
    for (int i = 0; i <= 100; i++) {
      ans += fr[i] * abs(i - x);
    }
    cout << ans << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  solve();

  return 0;
}
