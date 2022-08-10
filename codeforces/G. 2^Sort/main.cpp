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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int &i : a)
    cin >> i;

  int cnt = 0;
  std::cerr << "--------" << std::endl;
  debug(a);
  bool ok;
  for (int i = 0; i < n - k; i++) {
    ok = true;
    for (int j = i; j < i + k; j++) {
      if (a[j] >= a[j + 1] << 1) {
        ok = false;
        break;
      }
    }
    if (ok) {
      debug(i);
      cnt++;
    }
  }

  std::cout << cnt << std::endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t_case;
  while (t_case--)
    solve();
  return 0;
}
