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

vector<int> a;

template <typename T> struct segtree {
  vector<T> tree;
  bool updating;
  T default_value;
  function<T(T, T)> operation;

  segtree(
      size_t n, T default_value,
      function<T(T, T)> operation = [](T l, T r) { return l; })
      : default_value(default_value), operation(operation) {
    // Ceil it to the next pow of 2. Expected issue when `n` is
    // so huge that the next pow of 2 can't fit in 64 bits. This
    // is equivalent to: `pow(2, ceil(log(n)))`
    if (__builtin_popcountll(n) > 1)
      n = 1ull << (64 - __builtin_clzll(n));
    tree.assign(n << 1, default_value);
  }

  T q(size_t node, size_t node_low, size_t node_high, size_t query_low,
      size_t query_high, T &v) {
    if (query_high >= node_high && query_low <= node_low) {
      if (updating)
        tree[node] = v;
      return tree[node];
    }

    if (query_high < node_low || node_high < query_low) {
      if (updating)
        return tree[node];
      else
        return default_value; // first element with the default_value
    }

    size_t end_of_left = (node_high + node_low) >> 1;
    const T &l = q(node << 1, node_low, end_of_left, query_low, query_high, v);
    const T &r = q(node << 1 | 1, end_of_left + 1, node_high, query_low, query_high, v);
    const T &val = operation(l, r);

    if (updating)
      tree[node] = val;
    return val;
  }

  T query(size_t query_low, size_t query_high) {
    // default_value has nothing to do here, it is just a must to pass this argument
    return q(1, 0, (tree.size() >> 1) - 1, query_low, query_high, default_value);
  }

  void update(size_t i, T val) {
    updating = true;
    q(1, 0, (tree.size() >> 1) - 1, i, i, val);
    updating = false;
  }
};

typedef segtree<pair<int, int>> segtr;

int n;
segtr mn(0, {0, 0});
segtr mx(0, {0, 0});

int dis(int i, int j) {
  if (i == j)
    return 0;

  auto n = mn.query(i, j);
  auto x = mx.query(i, j);
  if (n.second > x.second)
    return dis(i, x.second) + 1 + dis(n.second, j);
  else
    return dis(i, n.second) + 1 + dis(x.second, j);
}

void solve() {
  cin >> n;

  mn = segtr(n, {INT_MAX, -1}, [](auto l, auto r) {
    if (l.first < r.first)
      return l;
    else
      return r;
  });

  mx = segtr(n, {0, -1}, [](auto l, auto r) {
    if (l.first > r.first)
      return l;
    else
      return r;
  });

  for (int i = 0; i < n; i++) {
    int ai;
    cin >> ai;
    mn.update(i, {ai, i});
    mx.update(i, {ai, i});
  }

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
