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

vector<vector<char>> m(50, vector<char>(50));
int n;

bool valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < n; }

int right(int x, int y) {
  x++;
  if (x < n && m[x][y] != '*')
    return x;
  x--;
  return x;
}

int left(int x, int y) {
  x--;
  if (x >= 0 && m[x][y] != '*')
    return x;
  x++;
  return x;
}

int up(int x, int y) {
  y--;
  if (y >= 0 && m[x][y] != '*')
    return y;
  y++;
  return y;
}

int down(int x, int y) {
  y++;
  if (y < n && m[x][y] != '*')
    return y;
  y--;
  return y;
}

map<array<int, 4>, bool> vis;

void solve() {
  cin >> n;

  pair<int, int> a, b;
  for (int i = 0; i < n; i++) {
    string r;
    cin >> r;
    for (int j = 0; j < n; j++) {
      m[i][j] = r[j];
      if (r[j] == 'a')
        a = {i, j};
      if (r[j] == 'b')
        b = {i, j};
    }
  }

  queue<array<int, 5>> qu; // player, steps, x, y
  qu.push({a.first, a.second, b.first, b.second, 0});

  while (!qu.empty()) {
    auto [x, y, i, j, s] = qu.front();
    qu.pop();
    if (vis[{x, y, i, j}])
      continue;
    vis[{x, y, i, j}] = true;

    vector<array<int, 5>> moves = {
        {right(x, y), y, right(i, j), j, s + 1},
        {left(x, y), y, left(i, j), j, s + 1},
        {x, up(x, y), i, up(i, j), s + 1},
        {x, down(x, y), i, down(i, j), s + 1},
    };

    for (auto move : moves) {
      if (move[0] == move[2] && move[1] == move[3]) {
        cout << move[4] << endl;
        return;
      }

      if (move[0] != x || move[1] != y || move[2] != i || move[3] != j) {
        qu.push(move);
      }
    }
  }

  cout << "no solution" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
