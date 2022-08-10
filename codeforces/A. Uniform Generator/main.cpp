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

void solve() {
  int step, mod;

  auto lcm = [](int value, int val) { return value * val / __gcd(value, val); };

  while (cin >> step >> mod) {
    string res = "Good Choice";
    if (__gcd(mod, step) != 1)
      res = "Bad Choice";
    // if (lcm(mod, seed) / seed != mod)
    //   res = "Bad Choice";
    printf("%10lld%10lld    %s\n", step, mod, res.c_str());
    puts("");
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string a;
  solve();
  return 0;
}
