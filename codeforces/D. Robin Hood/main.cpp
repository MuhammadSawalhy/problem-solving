// Date: 29-10-2022
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

  int n, k;
  cin >> n >> k;

  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  set<int> s(a, a + n);
  if (s.size() == 1) {
    cout << 0 << endl;
    return 0;
  }

  

  return 0;
}
