// Date: 15-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  // make segments and store the max of them

  auto comp = [](array<int, 4> l, array<int, 4> r) {
    return l[0] == r[0] ? l[3] > r[3] : l[0] < r[0];
  };

  priority_queue<array<int, 4>, vector<array<int, 4>>,
                 function<bool(array<int, 4>, array<int, 4>)>>
      qu(comp); // PQ of {length, order (index)}
  vector<array<int, 4>> segs;

  for (int i = 0; i < n;) {
    int val = a[i];
    int j = i;
    while (i < n && a[i] == val) {
      i++;
    }

    segs.push_back({i - j, val, (int)segs.size(), (int)segs.size()});
  }

  // sort(segs.begin(), segs.end(), comp);

  vector<pair<int, int>> lr(segs.size(), {-1, -1});
  vector<bool> deleted(segs.size());

  for (int i = 0; i < (int)segs.size(); i++) {
    if (i > 0)
      lr[i].first = i - 1;
    if (i + 1 < (int)segs.size())
      lr[i].second = i + 1;
  }

  debug(ITR, a, a + n);

  for (int i = 0; i < (int)segs.size(); i++) {
    qu.push(segs[i]);
  }

  int ans = 0;
  while (!qu.empty()) {
    debug(segs);
    debug(lr);
    debug(deleted);
    auto [l, val, i, j] = qu.top();
    qu.pop();

    if (deleted[i])
      continue;

    if (~lr[i].first && ~lr[i].second &&
        segs[lr[i].first][1] == segs[lr[i].second][1]) {
      // add the new segment
      deleted[lr[i].first] = true;
      deleted[lr[i].second] = true;
      segs.push_back({segs[lr[i].first][0] + segs[lr[i].second][0],
                      segs[lr[i].first][1], (int)segs.size(),
                      segs[lr[i].first][3]});
      lr.push_back({lr[lr[i].first].first, lr[lr[i].second].second});
      if (~lr.back().first) {
        lr[lr.back().first].second = (int)segs.size() - 1;
      }
      if (~lr.back().second) {
        lr[lr.back().second].first = (int)segs.size() - 1;
      }
      deleted.push_back(false);
      qu.push(segs.back());
    } else {
      // disconnect from adjacent
      if (~lr[i].second)
        lr[lr[i].second].first = lr[i].first;
      if (~lr[i].first)
        lr[lr[i].first].second = lr[i].second;
    }

    deleted[i] = true;

    ans++;
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  solve();

  return 0;
}
