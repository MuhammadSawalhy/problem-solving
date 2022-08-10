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

vi a;
int n;

enum status { contest, gym, rest };
vector<array<int, 3>> min_rests;

int min_rest(int i, int prev_status) {
  if (i == n) {
    return 0;
  }

  int &mymin = min_rests[i][prev_status];

  if (mymin != INT_MAX)
    return mymin;

  if (prev_status != contest && a[i] & 1) // contest
  {
    mymin = min(mymin, min_rest(i + 1, contest));
  }

  if (prev_status != gym && a[i] & 2) // gym
  {
    mymin = min(mymin, min_rest(i + 1, gym));
  }

  mymin = min(mymin, 1 + min_rest(i + 1, rest));

  return mymin;
}

void solve() {
  cin >> n;
  a.resize(n);
  min_rests =
      vector<array<int, 3>>(n, array<int, 3>({INT_MAX, INT_MAX, INT_MAX}));
  for (auto &i : a)
    cin >> i;
  int res = INT_MAX;
  res = min(res, min_rest(0, gym));
  res = min(res, min_rest(0, rest));
  res = min(res, min_rest(0, contest));
  debug(a);
  debug(min_rests);
  std::cout << res << std::endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
