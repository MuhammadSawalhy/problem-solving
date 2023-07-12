// Date: 15-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

vector<int> a;
array<vector<int>, 3> boxes;
long long ans = 0;
int n;

void doit(int i) {
  if (i == n) {
    long long sna = INT_MAX;
    for (int i = 0; i < (int)boxes[0].size(); i++) {
      for (int j = 0; j < (int)boxes[1].size(); j++) {
        for (int k = 0; k < (int)boxes[2].size(); k++) {
          sna = min(sna, abs((long long)boxes[0][i] - boxes[1][j]) +
                             abs(boxes[1][j] - boxes[2][k]));
        }
      }
    }
    if (sna != INT_MAX && sna > ans) {
      ans = sna;
      debug(boxes);
    }
    return;
  }

  boxes[0].push_back(a[i]);
  doit(i + 1);
  boxes[0].pop_back();
  boxes[1].push_back(a[i]);
  doit(i + 1);
  boxes[1].pop_back();
  boxes[2].push_back(a[i]);
  doit(i + 1);
  boxes[2].pop_back();
}

void solve() {
  cin >> n;
  a = vector<int>(n);
  boxes = array<vector<int>, 3>();
  for (int i = 0; i < n; i++)
    cin >> a[i];
  ans = 0;
  doit(0);

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
