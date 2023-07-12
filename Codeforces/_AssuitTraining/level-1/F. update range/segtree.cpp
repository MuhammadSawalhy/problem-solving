//============================================================================
// Problem     : F. update range
// Author      : Muahmmad Assawalhy
// Date        : 01-09-22
//============================================================================

#include <bits/stdc++.h>

using namespace std;

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
typedef vector<int> vi;
typedef vector<bool> vb;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()

template <typename T> struct segtree {
  vector<T> tree;
  bool updating;
  T default_value;
  function<T(T, T)> operation;

  segtree(
      size_t n, T default_value = 0,
      function<T(T, T)> operation = [](T l, T r) { return l + r; })
      : default_value(default_value), operation(operation) {
    // Ceil it to the next pow of 2. Expected issue when "n" is
    // so huge that the next pow of 2 can't fit in 64 bits. This
    // is equivalent to: "pow(2, ceil(log(n)))"
    if (__builtin_popcountll(n) > 1)
      n = 1ull << (64 - __builtin_clzll(n));
    tree.assign(n << 1, default_value);
  }

  T q(size_t node, size_t node_low, size_t node_high, size_t query_low,
      size_t query_high, T &v) {
    if (query_high >= node_high && query_low <= node_low) {
      if (updating)
        tree[node] += v;
      return tree[node];
    }

    if (query_high < node_low || node_high < query_low) {
      if (updating)
        return tree[node];
      else
        return default_value;
    }

    size_t end_of_left = (node_high + node_low) >> 1;
    const T &l = q(node << 1, node_low, end_of_left, query_low, query_high, v);
    const T &r =
        q(node << 1 | 1, end_of_left + 1, node_high, query_low, query_high, v);
    const T &val = tree[node] + operation(l, r);

    // if (updating)
    //   tree[node] = val;

    return val;
  }

  T query(size_t query_low, size_t query_high) {
    // default_value has nothing to do here, it is just a must to pass this
    // argument
    return q(1, 0, (tree.size() >> 1) - 1, query_low, query_high,
             default_value);
  }

  void update(size_t i, T val) {
    updating = true;
    q(1, 0, (tree.size() >> 1) - 1, i, i, val);
    updating = false;
  }

  void update(size_t i, size_t j, T val) {
    updating = true;
    q(1, 0, (tree.size() >> 1) - 1, i, j, val);
    updating = false;
  }
};

void solve() {
  int n, q;
  cin >> n >> q;

  segtree<ull> seg(n);

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    seg.update(i, v);
  }

  while (q--) {
    int l, r, val;
    cin >> l >> r >> val;
    l--, r--;
    seg.update(l, r, val);
  }

  debug(seg.tree);

  for (int i = 0; i < n; i++) {
    cout << seg.query(i, i) << " \n"[i == n - 1];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
