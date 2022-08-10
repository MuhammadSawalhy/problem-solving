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
vector<vector<int>> adj;
vector<bool> vis;
vector<int> order;

void top_sort(int i) {
  if (vis[i])
    return;
  vis[i] = true;

  for (int j : adj[i])
    top_sort(j);

  order.push_back(i);
}

void solve() {
  while (true) {
    int n, m;
    cin >> n >> m;
    if (n == 0)
      break;
    adj.clear();
    vis.clear();
    order.clear();
    adj.resize(n + 1);
    vis.resize(n + 1);

    for (int i = 1; i <= m; i++) {
      int j, v;
      cin >> j >> v;
      adj[v].push_back(j);
    }

    for (int i = 1; i <= n; i++)
      top_sort(i);

    debug(adj);
    debug(vis);
    debug(order);

    for (int i : order)
      std::cout << i << " \n"[i == order.back()];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
