// Date: 19-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int n;
  cin >> n;

  vector<array<int, 2>> intervals(n), ans;

  for (int i = 0; i < n; i++) {
    cin >> intervals[i][0] >> intervals[i][1];
  }

  sort(intervals.begin(), intervals.end());

  for (int i = 0; i < n; i++) {
    if (ans.empty() || ans.back()[1] < intervals[i][0])
      ans.push_back(intervals[i]);
    else
      ans.back()[1] = max(ans.back()[1], intervals[i][1]);
  }

  for (auto [l, r] : ans)
    cout << l << " " << r << endl;

  return 0;
}
