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

string b;

bool iswin(string board) {
  int xwins = 0, owins = 0;
  const vector<vector<pair<int, int>>> win_cases = {
      {{0, 0}, {0, 1}, {0, 2}}, {{1, 0}, {1, 1}, {1, 2}},
      {{2, 0}, {2, 1}, {2, 2}}, {{0, 0}, {1, 0}, {2, 0}},
      {{0, 1}, {1, 1}, {2, 1}}, {{0, 2}, {1, 2}, {2, 2}},
      {{0, 0}, {1, 1}, {2, 2}}, {{0, 2}, {1, 1}, {2, 0}},
  };

  char c;
  bool iswin;
  for (auto win : win_cases) {
    c = 'X';
    iswin = true;
    for (auto point : win) {
      if (board[point.first * 3 + point.second] != c) {
        iswin = false;
        break;
      }
    }

    if (iswin)
      return true;

    c = 'O';
    iswin = true;
    for (auto point : win) {
      if (board[point.first * 3 + point.second] != c) {
        iswin = false;
        break;
      }
    }

    if (iswin)
      return true;
  }

  return false;
}

bool isfull(string board) {
  bool res = true;

  for (char c : board) {
    res = res && c != '.';
  }

  return res;
}

bool isvalid(string cur, bool isx) {
  if (cur == b) {
    if (iswin(cur) || isfull(cur))
      return true;
    return false;
  }

  if (iswin(cur))
    return false;

  for (int i = 0; i < 9; i++) {
    if (cur[i] == '.') {
      cur[i] = isx ? 'X' : 'O';
      if (cur[i] == b[i] && isvalid(cur, !isx))
        return true;
      cur[i] = '.';
    }
  }

  return false;
}

void solve() {
  while (true) {
    cin >> b;
    if (b == "end")
      break;
    std::cout << (isvalid(".........", true) ? "valid" : "invalid")
              << std::endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
