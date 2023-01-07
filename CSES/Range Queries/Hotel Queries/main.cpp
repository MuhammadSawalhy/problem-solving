// Date: 12-10-2022
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#endif

// clang-format off
template <typename T> struct segtree {
  int n;
  vector<T> tree;
  vector<long long> updates;
  vector<long long> applied_updates;
  vector<long long> count;
  bool updating = false;
  bool is_delta_update = false;
  long long update_value;
  T default_value;
  function<T(T, T)> operation;
  function<void(int, long long)> delta_update_node = [](int node, long long delta) {};
  // for sum we will do this
  // [](int node, T delta) {
  //   tree[node] += delta * count[node];
  // };

  segtree(int n, T default_value = 0,
          function<T(T, T)> operation = [](T l, T r) { return l + r; }) {
    // Ceil it to the next pow of 2. Expected issue when "n" is
    // so huge that the next pow of 2 can't fit in 64 bits. This
    // is equivalent to: "pow(2, ceil(log(n)))"
    int _n = n;
    if (__builtin_popcountll(n) > 1)
      n = 1ull << (64 - __builtin_clzll(n));
    this->n = n;
    this->operation = operation;
    this->default_value = default_value;
    tree.assign(n << 1, default_value);
    updates.assign(n << 1, 0);
    applied_updates.assign(n << 1, 0);
    count.assign(n << 1, 0);
    for (int i = n; i < n + _n; i++)
      count[i] = 1;
    for (int i = n - 1; i >= 1; i--)
      count[i] = count[i << 1] + count[i << 1 | 1];
  }

  segtree(vector<T> &v, T default_value = 0,
          function<T(T, T)> operation = [](T l, T r) { return l + r; }) {
    segtree(v.size(), default_value, operation);
    for (int i = 0; i < v.size(); i++) {
      u(i, v[i]);
    }
  }

  T q(int node, int node_low, int node_high, int query_low,
      int query_high, long long comulative_update = 0) {

    comulative_update += updates[node];

    if (query_high >= node_high && query_low <= node_low) {
      if (updating) {
        // this should be customized with delta updates
        tree[node] = update_value;
        applied_updates[node] = comulative_update;
      }
      if (is_delta_update) {
        updates[node] += update_value; // to consider for childern in the future
        comulative_update += update_value; // consider for himself now
      }
      delta_update_node(node, comulative_update - applied_updates[node]);
      applied_updates[node] = comulative_update;
      return tree[node];
    }

    if (query_high < node_low || node_high < query_low) {
      if (updating || is_delta_update) {
        delta_update_node(node, comulative_update - applied_updates[node]);
        applied_updates[node] = comulative_update;
        return tree[node];
      }
      else
        return default_value;
    }

    int mid = (node_high + node_low) >> 1;
    const T &l = q(node << 1, node_low, mid, query_low, query_high, comulative_update);
    const T &r =
      q(node << 1 | 1, mid + 1, node_high, query_low, query_high, comulative_update);
    const T &val = operation(l, r);

    if (updating || is_delta_update) {
      tree[node] = val;
      // don't consider my comulative_update as my left and right did this already
      applied_updates[node] = comulative_update;
    }

    return val;
  }

  T query(int l, int r) {
    l = get_correct_index(l);
    r = get_correct_index(r);
    T val = q(1, 0, n - 1, l, r);
    return val;
  }

  void u(int i, long long val) {
    updating = true;
    update_value = val;
    q(1, 0, n - 1, i, i);
    updating = false;
  }

  void update(int i, long long val) {
    i = get_correct_index(i);
    u(i, val);
  }

  void delta_update(int l, int r, long long val) {
    is_delta_update = true;
    update_value = val;
    q(1, 0, n - 1, l, r);
    is_delta_update = false;
  }

  void e(int k) {
    u(k, default_value);
    count[n + k] = 0;
    for (int i = (n + k) >> 1; i >= 1; i >>= 1)
      count[i] = count[i << 1] + count[i << 1 | 1];
  }

  // You can't use delta_update with erase
  void erase(int k) {
    k = get_correct_index(k);
    e(k);
  }

  // with upperbounding
  int gci(int i, int node, int node_low, int node_high) {
    if (node_low == node_high) return node_low;
    int mid = (node_low + node_high) >> 1;
    int l = node << 1, r = node << 1 | 1;
    if (count[r] >= i)
      // go to the right if there exist enough nodes
      return gci(i, r, mid + 1, node_high);
    else
      // otherwise go to the left and subtract the right
      return gci(i - count[r], l, node_low, mid);
  }

  int get_correct_index(int i) {
    assert(i >= 0 && i < count[1]);
    return gci(count[1] - i, 1, 0, n - 1);
  }

  int search(T val, int node, int node_low, int node_high) {
    if (node_low == node_high) {
      if (tree[node] >= val)
        return node_low;
      return -1;
    }
    int mid = (node_low + node_high) / 2;
    if (tree[node << 1] >= val)
      return search(val, node << 1, node_low, mid);
    debug("right", mid + 1, node_high);
    return search(val, node << 1 | 1, mid + 1, node_high);
  }
};
// clang-format on

void solve() {
  int n, m;
  cin >> n >> m;
  segtree<int> sg(n, INT_MIN, [](auto l, auto r) { return max(l, r); });
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    sg.update(i, a);
  }

  while (m--) {
    int g;
    cin >> g;
    int i = sg.search(g, 1, 0, sg.n - 1);
    if (i >= 0)
      sg.update(i, sg.tree[i + sg.n] - g);
    cout << i + 1 << "\n "[!!m];
    debug(g, i);
    debug(sg.tree);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  solve();

  return 0;
}
