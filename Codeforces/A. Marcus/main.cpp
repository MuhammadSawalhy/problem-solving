#include <bits/stdc++.h>

using namespace std;

// clang-format off
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(x...)
#define debug_arr(arr, n)
#endif

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;

#define f(i, a, b) for (ll i = a; i < b; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()
#define pop_cnt(x) (__builtin_popcountll(x))
#define LSB(x) (__builtin_ffsll(x) - 1)
#define MSB(x) (64 - __builtin_clzll(x) - 1)
#define int ll

template <class T> inline void clear(T *arr, int val, int n) { while(n--) arr[n] = val; }
// clang-format on

int t_case;

int x, y;
string chars = "#IEHOVA";
vector<string> m(x);
vector<string> steps;

bool is_valid(int i, int j) { return i >= 0 && j >= 0 && i < x && j < y; }

void doit(int i, int j) {
  if (m[i][j] == '#')
    return;
  if (is_valid(i - 1, j)) {
    if (chars.find(m[i - 1][j]) != string::npos) {
      steps.push_back("forth");
      doit(i - 1, j);
    }
  }
  if (is_valid(i, j + 1)) {
    if (chars.find(m[i][j + 1]) != string::npos) {
      steps.push_back("right");
      m[i][j] = 'x'; // to prevent cycles
      doit(i, j + 1);
    }
  }
  if (is_valid(i, j - 1)) {
    if (chars.find(m[i][j - 1]) != string::npos) {
      steps.push_back("left");
      m[i][j] = 'x';
      doit(i, j - 1);
    }
  }
}

void solve() {
  cin >> x >> y;
  m.resize(x);
  for (string &s : m)
    cin >> s;
  steps.clear();
  debug(m);
  doit(x - 1, m.back().find('@'));
  std::cout << steps[0];
  for (ull i = 1; i < steps.size(); i++)
    std::cout << " " << steps[i];
  std::cout << std::endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t_case;
  while (t_case--)
    solve();
  return 0;
}
