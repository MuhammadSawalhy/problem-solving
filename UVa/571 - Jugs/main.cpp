//============================================================================
// Problem     : UVa Online Judge/571 - Jugs
// Author      : Muahmmad Assawalhy
// Date        : 30-08-22
//============================================================================

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

int a, b, n;

void solve() {
  vector<vector<bool>> vis(1000, vector<bool>(1001));
  vector<vector<string>> point(1000, vector<string>(1001));
  vector<vector<pair<int, int>>> parent(1000, vector<pair<int, int>>(1001));

  pair<int, int> e;
  queue<pair<int, int>> qu;
  qu.push({0, 0});

  while (!qu.empty()) {
    auto c = qu.front();
    qu.pop();

    if (vis[c.first][c.second])
      continue;
    vis[c.first][c.second] = true;

    if (c.second == n) {
      debug(c, n);
      e = c;
      break;
    }

    const vector<pair<pair<int, int>, string>> moves = {
        {{a, c.second}, "fill A"},
        {{0, c.second}, "empty A"},
        {{c.first, b}, "fill B"},
        {{c.first, 0}, "empty B"},
        {{c.first + c.second - min(b, c.first + c.second),
          min(b, c.first + c.second)},
         "pour A B"},
        {{min(a, c.first + c.second),
          c.second + c.first - min(a, c.first + c.second)},
         "pour B A"},
    };

    for (auto &[m, action] : moves) {
      if (!vis[m.first][m.second]) {
        parent[m.first][m.second] = c;
        point[m.first][m.second] = action;
        qu.push(m);
      }
    }
  }

  vector<string> ans;
  while (e.first || e.second) {
    ans.push_back(point[e.first][e.second]);
    e = parent[e.first][e.second];
  }

  while (!ans.empty()) {
    cout << ans.back() << endl;
    ans.pop_back();
  }

  cout << "success" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> a >> b >> n) {
    solve();
  }

  return 0;
}
