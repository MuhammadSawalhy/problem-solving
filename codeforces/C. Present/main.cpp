// Date: 25-09-22
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
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
        tree[node] = {update_value, query_low};
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
};
// clang-format on

void solve() {
  int n, m, w;
  cin >> n >> m >> w;
  segtree<pair<long long, int>> a(n, {LONG_LONG_MAX, -1}, [](auto l, auto r) {
    return l.first <= r.first ? l : r;
  });
  a.delta_update_node = [&a](int node, long long del) {
    a.tree[node] = {a.tree[node].first + del, a.tree[node].second};
  };

  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    a.update(i, b);
  }

  while (m--) {
    // get the index of the smallest element and increase a range
    auto x = a.query(0, n - 1);
    int i = x.second;
    int j = i + w - 1;
    if (j >= n) {
      // shift to the left
      i -= (j - (n - 1));
      j = n - 1;
    }

    a.delta_update(i, j, 1LL);
  }

  cout << a.query(0, n - 1).first << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t_cases = 1;
  // cin >> t_cases;
  while (t_cases--) {
    solve();
  }
  return 0;
}
