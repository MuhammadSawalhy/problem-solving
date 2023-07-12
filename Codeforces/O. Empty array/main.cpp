// Date: 23-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  sort(all(a));
  vector<vector<int>> ans;

  map<int, int> ind;
  for (auto i : a) {
    int j = ind[i];
    while (j >= ans.size()) {
      ans.push_back({});
    }
    ans[j].push_back(i);
    ind[i]++;
  }

  for (auto v : ans) {
    for (auto x : v) {
      cout << x << " ";
    }
    cout << endl;
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  solve();

  return 0;
}
