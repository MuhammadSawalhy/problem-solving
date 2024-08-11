#include <bits/stdc++.h>

using namespace std;

// clang-format off
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_arr(...)
#define debug_bits(...)
#endif

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;

#define int ll
#define f(i, b) for (ll i = 0; i < b; i++)
#define ff(i, a, b) for (ll i = a; i < b; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()
#define sum(v) accumulate(all(v), 0)
#define pop_cnt(x) (__builtin_popcountll(x))
#define LSB(x) (__builtin_ffsll(x) - 1)
#define MSB(x) (64 - __builtin_clzll(x) - 1)

typedef vector<int> vi;
typedef vector<bool> vb;

template <class T> inline void clear(T *arr, int val, int n) { while(n--) arr[n] = val; }
// clang-format on

int t_case;

void solve() {
  string r[3];
  cin >> r[0];
  cin >> r[1];
  cin >> r[2];

  int x = 0, o = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      char c = r[i][j];
      if (c == 'X')
        x++;
      else if (c == 'O')
        o++;
    }
  }

  int xwins = 0, owins = 0;
  vector<vector<pair<int, int>>> win_cases = {
      {{0, 0}, {0, 1}, {0, 2}}, {{1, 0}, {1, 1}, {1, 2}},
      {{2, 0}, {2, 1}, {2, 2}}, {{0, 0}, {1, 0}, {2, 0}},
      {{0, 1}, {1, 1}, {2, 1}}, {{0, 2}, {1, 2}, {2, 2}},
      {{0, 0}, {1, 1}, {2, 2}}, {{0, 2}, {1, 1}, {2, 0}},
  };

  for (auto win : win_cases) {
    char c;
    c = 'X';
    bool iswin = true;

    for (auto point : win) {
      if (r[point.first][point.second] != c) {
        iswin = false;
        break;
      }
    }

    if (iswin)
      xwins++;

    c = 'O';
    iswin = true;

    for (auto point : win) {
      if (r[point.first][point.second] != c) {
        iswin = false;
        break;
      }
    }

    if (iswin)
      owins++;
  }

  debug(x, o);
  debug(xwins, owins);
  bool isok = abs(x - o) <= 1 && x >= o && xwins <= 2 && owins <= 1;
  isok = isok && (!owins && xwins || !xwins && owins || !xwins && !owins);
  isok = isok && (owins && x == o || !owins);
  std::cout << (isok ? "yes" : "no") << std::endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t_case;
  while (t_case--)
    solve();
  return 0;
}
