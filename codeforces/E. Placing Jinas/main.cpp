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

void solve1() {
  int n;
  cin >> n;
  vi v;
  v.resize(2);
  vi a = {1, 2, 3}, b = {2, 3, 4, 5};
  set_difference(all(b), all(a), v.begin());
  v.clear();
  set_intersection(all(a), all(b), back_inserter(v));
  v.clear();
  set_union(all(a), all(b), back_inserter(v));
  debug(a);
  debug(b);
  debug(v);
  v.resize(unique(all(v)) - v.begin());
  debug(v);
  v.clear();
  set_symmetric_difference(all(a), all(b), back_inserter(v));
  debug(v);

  complex<double> c;
  c.imag(1);
  c.real(4);
  debug(c);
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t_case;
  while (t_case--)
    solve1();
  return 0;
}
