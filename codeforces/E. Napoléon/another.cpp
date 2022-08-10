#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()

int n;
bool grid[20][20];

void solve() {
  int xc, yc, xt, yt;
  cin >> xc >> yc >> xt >> yt;

  queue<array<int, 3>> qu;
  qu.push({xc, yc, 0});

  while (!qu.empty()) {
    auto &[x, y, s] = qu.front();
    qu.pop();

    if (!(x >= 0 && x < n) || !(y >= 0 && y < n))
      continue;

    if (grid[x][y])
      continue;
    grid[x][y] = true;

    if (x == xt && y == yt) {
      cout << s << endl;
      return;
    }

    qu.push({x + 1, y + 1, s + 1});
    qu.push({x + 1, y - 1, s + 1});
    qu.push({x - 1, y - 1, s + 1});
    qu.push({x - 1, y + 1, s + 1});
  }

  cout << "can't reach!" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_cases;
  cin >> t_cases;
  cin >> n;
  while (t_cases--) {
    memset(grid, 0, sizeof(grid));
    solve();
  }

  return 0;
}
