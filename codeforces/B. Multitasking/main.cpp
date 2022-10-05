// Date: 03-10-22
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> ans;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  auto check = [&](int i, int j) -> bool {
    bool status = false;
    for (auto &b : a) {
      if (b[i] > b[j]) {
        swap(b[i], b[j]);
        status = true;
      }
    }

    return status;
  };

  if (k) {
    for (int j = 0; j < m - 1; j++)
      for (int i = m - 1; i > j; i--) {
        if (check(i, i - 1)) {
          ans.emplace_back(i, i - 1);
        }
      }
  } else {
    for (int j = m - 1; j > 0; j--)
      for (int i = 0; i < j; i++) {
        if (check(i, i + 1)) {
          ans.emplace_back(i, i + 1);
        }
      }
  }

  cout << ans.size() << endl;
  for (auto [i, j] : ans)
    cout << i + 1 << " " << j + 1 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  solve();
  return 0;
}
