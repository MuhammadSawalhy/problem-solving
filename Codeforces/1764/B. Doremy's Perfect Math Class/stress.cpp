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
  int n;
  cin >> n;
  set<int> s;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    s.insert(v[i]);
  }

  bool ok = true;
  while (ok) {
    ok = false;
    for (int i = 0; i < (int) v.size(); i++) {
      for (int j = i + 1; j < (int) v.size(); j++) {
        int x = abs(v[j] - v[i]);
        if (s.count(x)) continue;
        v.push_back(x);
        s.insert(x);
        ok = true;
      }
    }
  }

  cout << s.size() << endl;
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
