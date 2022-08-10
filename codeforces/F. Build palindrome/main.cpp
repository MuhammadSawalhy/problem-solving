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
string s;

bool is_odd_pal(int i) {
  for (int j = 1; j <= s.size() - i - 1; ++j) {
    if (s[i + j] != s[i - j])
      return false;
  }
  return true;
}

bool is_even_pal(int i, int j) {
  for (int k = 0; k <= s.size() - 1 - j; k++) {
    if (s[i - k] != s[j + k])
      return false;
  }
  return true;
}

void solve() {
  cin >> s;

  int ans = s.size() - 1;

  int i = s.size() / 2;

  if (s.size() % 2 == 0) {
    if (is_even_pal(i - 1, i)) {
      std::cout << 0 << std::endl;
      return;
    }
    if (is_odd_pal(i)) {
      std::cout << 1 << std::endl;
      return;
    }
    i++;
  }

  std::cerr << s << std::endl;

  while (i < s.size() - 1) {
    if (is_odd_pal(i)) {
      std::cerr << "odd" << std::endl;
      debug(i);
      std::cout << i - (s.size() - i - 1) << std::endl;
      return;
    }
    if (is_even_pal(i - 1, i)) {
      std::cerr << "even" << std::endl;
      debug(i);
      std::cout << i - (s.size() - i) << std::endl;
      return;
    }
    i++;
  }

  std::cout << ans << std::endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t_case;
  while (t_case--)
    solve();
  return 0;
}
