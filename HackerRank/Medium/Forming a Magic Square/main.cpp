#include <bits/stdc++.h>

using namespace std;

// clang-format off
#ifndef ONLINE_JUDGE
#include "../../../debug.hpp"
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

void solve() {
  vector<vector<int>> m;
  for (int i = 0; i < 3; i++) {
    m.push_back({0, 0, 0});
    for (int j = 0; j < 3; j++) {
      cin >> m[i][j];
    }
  }

  // sums
  int rows = 0;
  int cols = 0;

  for (int i = 0; i < 3; i++) {
    int s1 = 0, s2 = 0;

    for (int j = 0; j < 3; j++) {
      s1 += m[i][j];
      s2 += m[j][i];
    }

    rows += abs(15 - s1);
    cols += abs(15 - s2);
  }

  std::cout << max(rows, cols) << std::endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
