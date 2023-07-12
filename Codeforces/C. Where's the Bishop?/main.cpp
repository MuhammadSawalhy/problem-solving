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
int n;

int count(string &s) {
  int cnt = 0;
  for (char c : s) {
    if (c == '#')
      cnt++;
  }
  return cnt;
}

void solve() {
  string row[8] = {""};

  for (int i = 0; i < 8; i++) {
    cin >> row[i];
  }

  for (int i = 1; i < 7; i++) {
    // equivalent to a == b && c == 1
    if (count(row[i - 1]) == count(row[i + 1]) == count(row[i])) {
      for (int k = 0; k < 8; k++) {
        if (row[i][k] == '#') {
          std::cout << i + 1 << " " << k + 1 << std::endl;
          return;
        }
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t_case;
  while (t_case--)
    solve();
  return 0;
}
