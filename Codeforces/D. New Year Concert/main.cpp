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
  int n;
  cin >> n;
  vi a(n);
  int need_change = 0;
  int gcd;
  int counter = 1;
  cin >> a[0];
  gcd = a[0];
  for (int i = 1; i <= n; i++) {
    if (gcd == counter) {
      need_change++;
      counter = 0;
      gcd = -1;
    }

    std::cout << need_change << " \n"[i == n];

    if (i != n) {
      cin >> a[i];
      if (gcd == -1)
        gcd = a[i];
      else
        gcd = __gcd(gcd, a[i]);
      counter++;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
