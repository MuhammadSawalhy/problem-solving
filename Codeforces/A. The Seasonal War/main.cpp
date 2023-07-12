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

void solve() {

  int nnn = 0;
  while (true) {
    nnn++;
    int n;
    if (!(cin >> n))
      break;
    int counter = 0;
    vector<vector<int>> b;
    vector<vector<int>> e;

    for (int i = 0; i < n; ++i) {
      vector<int> v(n);
      vector<int> v2(n);
      e.push_back(v);
      b.push_back(v2);
      for (int j = 0; j < n; ++j) {
        char k = cin.get();
        if (k == '\n')
          k = cin.get();
        b[i][j] = k - '0';
      }
    }

    vector<pair<int, int>> ops;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!b[i][j])
          continue;
        if (e[i][j])
          continue;
        e[i][j] = ++counter;

        ops.push_back({i, j});
        while (ops.size()) {
          debug(ops);
          auto c = ops.back();
          ops.pop_back();
          int i = c.first, j = c.second;

          auto doit = [&](int i, int j) {
            bool ok = i >= 0 && i < n && j >= 0 && j < n && b[i][j] && !e[i][j];
            if (ok) {
              ops.push_back({i, j});
              e[i][j] = counter;
            }
            return ok;
          };

          int di[8] = {1, 1, 1, 0, 0, -1, -1, -1};
          int dj[8] = {0, 1, -1, 1, -1, 0, 1, -1};
          for (int k = 0; k < 8; k++)
            doit(i + di[k], j + dj[k]);
        }
      }
    }

    debug(b);
    debug(e);

    std::cout << "Image number " << nnn << " contains " << counter
              << " war eagles." << std::endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
