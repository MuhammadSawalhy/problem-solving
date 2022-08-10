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

int binary_search_l(vi &v, int val) {
  int s = -1, e = v.size() - 1;

  while (e > s) {
    int mid = (e + s + 1) >> 1;
    if (v[mid] >= val)
      e = mid - 1;
    else
      s = mid;
  }

  return s;
}

int binary_search_u(vi &v, int val) {
  int s = 0, e = v.size();

  while (e > s) {
    int mid = (e + s) >> 1;
    if (v[mid] <= val)
      s = mid + 1;
    else
      e = mid;
  }

  return s == v.size() ? -1 : s;
}

void solve() {
  int N, Q;
  cin >> N;
  vi n(N);
  for (auto &i : n)
    cin >> i;

  debug(n);

  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int q;
    cin >> q;
    debug(q);

    auto lo = binary_search_l(n, q);
    auto up = binary_search_u(n, q);

    if (lo == -1)
      cout << "X";
    else {
      std::cout << n[lo];
    }

    if (up == -1)
      cout << " X" << endl;
    else
      cout << " " << n[up] << endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
