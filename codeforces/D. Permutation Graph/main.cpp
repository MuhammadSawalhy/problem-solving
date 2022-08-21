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

int n;
vector<int> a;

int dis(int i, int j) {
  if (i == j)
    return 0;

  auto mnx = minmax_element(a.begin() + i, a.begin() + j + 1);
  int mn = mnx.first - a.begin();
  int mx = mnx.second - a.begin();
  if (mx < mn)
    swap(mn, mx);
  return dis(i, mn) + 1 + dis(mx, j);
}

void solve() {
  cin >> n;
  a = vector<int>(n);
  for (int &i : a)
    cin >> i;

  cout << dis(0, n - 1) << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_case;
  cin >> t_case;
  while (t_case--)
    solve();
  return 0;
}
