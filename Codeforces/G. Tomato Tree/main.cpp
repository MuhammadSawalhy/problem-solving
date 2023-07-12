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
vector<vector<int>> n;
vector<bool> b;
vector<int> ans;

void doit(int i) {
  for (int j : n[i]) {
    doit(j);
    if (!b[j])
      ans[i] += ans[j];
  }
}

void solve() {
  int N, B, E;
  cin >> N >> B >> E;
  n.clear();
  b.clear();
  ans.clear();
  n.resize(N + 1);
  b.resize(N + 1);
  ans.resize(N + 1);

  for (int i = 2; i <= N; i++) {
    int j;
    cin >> j;
    n[j].push_back(i);
  }

  for (int i = 0; i < B; i++) {
    int j;
    cin >> j;
    b[j] = true;
  }

  for (int i = 0; i < E; i++) {
    int j;
    cin >> j;
    ans[j]++;
  }

  debug(n);
  debug(b);

  doit(1);

  debug(ans);

  for (int i = 1; i <= N; ++i) {
    std::cout << ans[i] << " \n"[i == N];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
