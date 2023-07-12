#include <bits/stdc++.h>

using namespace std;

// clang-format off
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(x...)
#define debug_arr(arr, n)
#endif

template <class T> inline void clear(T *arr, int val, int n) { while(n--) arr[n] = val; }
// clang-format on

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;

#define f(i, a, b) for (ll i = a; i < b; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()
#define mp(x, y) make_pair(x, y)
#define popCnt(x) (__builtin_popcountll(x))
#define LSB(x) (__builtin_ffsll(x) - 1)
#define MSB(x) (64 - __builtin_clzll(x) - 1)
#define int ll

int t_case;
int n;

void solve() {
  string s, t;

  cin >> n;
  cin >> s;
  cin >> t;

  vector<pair<char, int>> map;
  map.reserve(n / 2);

  map.push_back({s[0], 1});
  for (int i = 1; i < n; i++) {
    if (map.back().first == s[i])
      map.back().second++;
    else
      map.push_back({s[i], 1});
  }

  reverse(map.begin(), map.end());

  std::cerr << "------------------" << std::endl;
  debug(map);

  ull sz;
  for (int i = 0; i < n; i++) {
    debug(i, map);
    sz = map.size();

    if (sz == 0) {
      std::cout << "NO" << std::endl;
      return;
    }

    if (sz > 1 && map.back().first == map[sz - 2].first) {
      map[sz - 2].second += map.back().second;
      map.pop_back();
      sz = map.size();
    }

    if (t[i] == map.back().first) {
      map.back().second--;
      if (map.back().second == 0)
        map.pop_back();
    } else {
      if (sz == 1) {
        std::cout << "NO" << std::endl;
        return;
      }

      if (t[i] == 'b' && map.back().first == 'a' && map[sz - 2].first == 'b' ||
          t[i] == 'c' && map.back().first == 'b' && map[sz - 2].first == 'c') {
        map[sz - 2].second--;
        if (map[sz - 2].second == 0) {
          char c = map.back().first;
          int m = map.back().second;
          map.pop_back();
          map.pop_back();
          map.push_back({c, m});
        }
      } else {
        std::cout << "NO" << std::endl;
        return;
      }
    }
  }

  std::cout << "YES" << std::endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t_case;

  while (t_case--) {
    solve();
  }

  return 0;
}
