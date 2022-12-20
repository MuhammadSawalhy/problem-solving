// Date: 19-11-2022
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

  int a[n / 2];
  set<int> s;
  bool ok = true;
  for (int i = 0; i < n / 2; i++) {
    cin >> a[i];
    ok = ok && !s.count(a[i]);
    s.insert(a[i]);
  }

  if (!ok) return void(cout << -1 << endl);

  set<int> pool;
  for (int i = 1; i <= n; i++) {
    if (!s.count(i))
      pool.insert(i);
  }

  map<int, int> ans;

  for (int i = n / 2 - 1; ~i; i--) {
    auto j = pool.lower_bound(a[i]);
    if (j == pool.begin()) {
      cout << -1 << endl;
      return;
    }

    j--;
    ans[a[i]] = *j;
    pool.erase(j);
  }

  assert(ans.size() == n / 2);
  for (int i = 0; i < n / 2; i++)
    cout << ans[a[i]] << " " << a[i] << " ";
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
