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
  int n;
  cin >> n;
  int ans = 0; // zero or less
  int tracker = 1;
  int prev;
  cin >> prev;
  bool isup = false;

  int same = 1;
  for (int i = 1; i < n; i++) {
    int j;
    cin >> j;

    if (j > prev && !isup) {
      ans = max(ans, tracker);
      tracker = same;
      debug(same, j);
      isup = true;
    } else if (j < prev) {
      isup = false;
    }

    tracker++;
    if (j == prev) {
      same++;
    } else {
      same = 1;
    }

    prev = j;
  }

  ans = max(ans, tracker);
  std::cout << ans << std::endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
