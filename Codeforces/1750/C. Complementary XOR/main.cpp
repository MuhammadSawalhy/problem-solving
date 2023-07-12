// Date: 06-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

string inv(string a) {
  string res;
  for (int i = 0; i < (int) a.size(); i++) {
    res += '0' + ('1' - a[i]);
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;

  bool inversed = inv(a) == b;

  if (a != b && !inversed) {
    cout << "NO" << endl;
    return;
  }

  if (a == string(n, '0') && a == b) {
    cout << "YES" << endl;
    cout << 0 << endl;
    return;
  }

  vector<pair<int, int>> ans;

  vector<int> flips(n);

  int f = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == '1') {
      f++;
      flips[i]--;
      ans.push_back({i, i});
    }
  }

  bool ok = false;
  for (int i = 0; i < n; i++) {
    flips[i] += f;
    if ((flips[i] & 1) && b[i] == '1' || (~flips[i] & 1) && b[i] == '0') {
      ok = true;
    } else {
      assert(!ok);
    }
  }

  if (!ok || a == string(n, '0')) {
    // 000
    // 111
    ans.push_back({0, n - 1});
    ans.push_back({0, 0});
    ans.push_back({1, n - 1});
  }

  assert(ans.size() > 0 && ans.size() <= n + 5);
  cout << "YES" << endl;
  cout << ans.size() << endl;
  for (auto [l, r]: ans)
    cout << l + 1 << " " << r + 1 << endl;
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
