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

bool is_last_day_in_month(map<char, int> &d) {
  if (d['d'] < 28)
    return false;

  if (d['m'] == 2 && d['d'] == 29)
    return true;

  if (d['m'] == 2 && d['d'] == 28 && d['y'] % 4 != 0)
    return true;

  if (d['m'] == 1 || d['m'] == 3 || d['m'] == 5 || d['m'] == 7 || d['m'] == 8 ||
      d['m'] == 10 || d['m'] == 12)
    return d['d'] == 31;

  return d['d'] == 30;
}

void solve() {
  int n;
  while (true) {
    cin >> n;
    if (n == 0)
      break;

    int res = 0;
    int cost = 0;

    map<char, int> day;
    map<char, int> pday;

    for (char k : {'d', 'm', 'y', 'c'}) {
      cin >> day[k];
    }

    std::cerr << "====================================" << std::endl;
    for (int i = 1; i < n; ++i) {
      pday = day;
      for (char k : {'d', 'm', 'y', 'c'}) {
        cin >> day[k];
      }

      if (day['y'] - pday['y'] == 0) {
        if (day['m'] - pday['m'] == 0) {
          if (day['d'] - pday['d'] == 1) {
            res++;
            cost += day['c'] - pday['c'];
            std::cerr << "------" << std::endl;
            debug(pday);
            debug(day);
          }
        } else if (day['m'] - pday['m'] == 1) {
          if (is_last_day_in_month(pday) && day['d'] == 1) {
            res++;
            cost += day['c'] - pday['c'];
            std::cerr << "------" << std::endl;
            debug(pday);
            debug(day);
          }
        }
      } else if (day['y'] - pday['y'] == 1) {
        if (day['m'] == 1 && pday['m'] == 12) {
          if (day['d'] == 1 && pday['d'] == 31) {
            res++;
            cost += day['c'] - pday['c'];
            std::cerr << "------" << std::endl;
            debug(pday);
            debug(day);
          }
        }
      }
    }

    std::cout << res << " " << cost << std::endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
