// Date: 07-12-2022
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
  bool ok = true;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == -1)
      a[i] = 0;
    if (a[i] >= i + 1)
      ok = false;
  }

  if (!ok) {
    cout << -1 << endl;
    return;
  }

  priority_queue<int> pq;
  for (int i = 1; i <= n; i++) pq.push(i);

  vector<int> ans(n);

  function<void(int)> dfs = [&](int i) {
    if (ans[i]) return;
    if (a[i]) dfs(a[i] - 1);
    ans[i] = pq.top();
    pq.pop();
  };

  for (int i = n - 1; ~i; i--)
    dfs(i);

  vector<pair<int, int>> recon;// to reconstruct a from ans
  for (int i = 0; i < n; i++) {
    while (!recon.empty() && recon.back().first < ans[i]) {
      recon.pop_back();
    }

    if (recon.empty()) {
      if (a[i] != 0) {
        cout << -1 << endl;
        return;
      }
    } else {
      if (a[i] - 1 != recon.back().second) {
        cout << -1 << endl;
        return;
      }
    }

    recon.push_back({ans[i], i});
  }

  for (int i = 0; i < n; i++)
    cout << ans[i] << " \n"[i == n - 1];
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
