// Date: 12-10-2022
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#endif

int nc, nm;
void solve() {

  vector<pair<int, int>> connections;
  vector<string> events;

  while (nc--) {
    int n;
    cin >> n;
    for (int i = n; i--;) {
      string e;
      cin >> e;

      // connect events
      if (i != n - 1)
        connections.push_back({events.size() - 1, events.size()});

      events.push_back(e);
    }
  }

  cin >> nm;
  int n = events.size();
  while (nm--) {
    string s, t;
    cin >> s >> t;
    int is, it;
    for (int i = 0; i < n; i++) {
      if (events[i] == s)
        is = i;
      if (events[i] == t)
        it = i;
    }

    connections.push_back({is, it});
  }

  vector<vector<int>> mat(n, vector<int>(n, 1e7));
  for (int i = 0; i < n; i++)
    mat[i][i] = 0;
  for (auto [i, j] : connections)
    mat[i][j] = 1;

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
      }
    }
  }

  queue<pair<int, int>> con;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (mat[i][j] == 1e7 && mat[j][i] == 1e7) {
        con.push({i, j});
      }
    }
  }

  if (con.size()) {
    cout << con.size() << " concurrent events:" << endl;
    cout << "(" << events[con.front().first] << "," << events[con.front().second]
         << ")";
    con.pop();
    if (con.size())
      cout << " (" << events[con.front().first] << ","
           << events[con.front().second] << ")";
    cout << endl;
  } else {
    cout << "no concurrent events." << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int t = 0;
  while (cin >> nc, nc) {
    cout << "Case " << ++t << ", ";
    solve();
  }

  return 0;
}
