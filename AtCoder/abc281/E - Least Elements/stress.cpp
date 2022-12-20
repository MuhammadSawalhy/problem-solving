// Date: 10-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

void solve() {
  
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i <= n - m; i++) {
    vector<int> b(a.begin() + i, a.begin() + i + m);
    sort(all(b));
    cout << accumulate(b.begin(), b.begin() + k, 0LL) << " ";
  }

  cout << endl;

  return 0;
}
