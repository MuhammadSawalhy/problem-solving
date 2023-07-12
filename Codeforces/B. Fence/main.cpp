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

int t_case;

void solve() {
  int n, k;
  cin >> n >> k;
  vi h(n + 1);
  vi s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    s[i] = h[i];
    s[i] += s[i - 1];
  }

  debug(h);
  debug(s);

  int ans = 0;
  int minh = LONG_LONG_MAX;
  for (int i = k; i <= n; i++) {
    if (s[i] - s[i - k] < minh) {
      minh = s[i] - s[i - k];
      ans = i - k + 1;
    }
  }

  std::cout << ans << std::endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
