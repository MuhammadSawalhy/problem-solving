#include <bits/stdc++.h>

using namespace std;

// clang-format off
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
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

void solve() {
  int n;
  cin >> n;

  // I will always be in the range [-499, 500]
  // because a + g = 1000, always
  int d = 0;
  int a, b;
  while (n--) {
    cin >> a >> b;
    d += a;
    if (d <= 500)
      cout << "A";
    else {
      cout << "G";
      d -= 1000;
    }
  }

  cout << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
