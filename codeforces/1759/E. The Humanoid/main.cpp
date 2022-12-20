// Date: 18-11-2022
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
  ll h;
  cin >> n >> h;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(all(a));

  vector<int> values = {2, 2, 3};
  int ans = 0;

  auto dfs = [&](vector<int> values) {
    int j;
    long long hh = h;
    for (j = 0; j < n;) {
      if (a[j] < hh) {
        hh += a[j] / 2;
        j++;
      } else {
        if (values.empty()) {
          break;
        }
        hh *= values.back();
        values.pop_back();
      }
    }

    ans = max(j, ans);
  };

  do {
    debug(a, values);
    dfs(values);
    debug(ans, values);
  } while (next_permutation(all(values)));

  cout << ans << endl;
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
