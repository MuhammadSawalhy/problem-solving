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

int num;
int row, col;
int board[9][9];
int sol[9];

void mark(int r, int c, bool dir) {
  if (c == 8)
    return;

  int v = 1 - 2 * !dir; // 1 or -1
  int j;
  for (int i = 1; i <= 8; i++) {
    board[i][c] += v; // col
    board[r][i] += v; // row
    j = c + abs(r - i);
    if (j <= 8)
      board[i][j] += v; // diagonal (+ve slope)
    j = c - abs(r - i);
    if (j >= 1)
      board[i][j] += v; // diagonal (-ve slope)
  }
}

void doit(int c) {
  if (c == 9) {
    if (sol[col] != row)
      return;
    printf("%2d     ", ++num);
    for (int r = 1; r <= 8; r++)
      printf(" %d", sol[r]);
    puts("");
    return;
  }

  for (int r = 1; r <= 8; r++) {
    if (!board[r][c]) {
      sol[c] = r;
      mark(r, c, true);
      doit(c + 1);
      mark(r, c, false);
    }
  }
}

void solve() {
  cin >> row >> col;
  num = 0;
  puts("SOLN       COLUMN");
  puts(" #      1 2 3 4 5 6 7 8\n");
  doit(1);
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int t_cases;
  cin >> t_cases;
  while (t_cases--) {
    solve();
    if (t_cases)
      puts("");
  }
  return 0;
}
