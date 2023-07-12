// ----------------------------------------------------------------------------
// Problem : 12532 - Interval Product
// Author  : Muahmmad Assawalhy
// Date    : 18-09-22
// ----------------------------------------------------------------------------

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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef unsigned long long ull;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()

// clang-format off
template <typename T> struct segtree {
  int n;
  vector<T> tree;
  vector<T> updates;
  vector<T> applied_updates;
  vector<T> count;
  bool updating = false;
  bool is_delta_update = false;
  T update_value;
  T default_value;
  function<T(T, T)> operation;
  function<void(int, T)> delta_update_node = [](int node, T delta) {};
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
      int query_high, T comulative_update = 0) {

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

  void u(int i, T val) {
    updating = true;
    update_value = val;
    q(1, 0, n - 1, i, i);
    updating = false;
  }

  void update(int i, T val) {
    i = get_correct_index(i);
    u(i, val);
  }

  void delta_update(int l, int r, T val) {
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

int getx(int x) {
  if (x == 0)
    return 0;
  if (x < 0)
    return -1;
  else return 1;
}

char getthis(int v) {
  if (v == 0)
    return '0';
  if (v < 0)
    return '-';
  return '+';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  while (cin >> n >> k) {
    segtree<int> sg(n, 1, [](int l, int r) { return l * r; });
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      sg.update(i, getx(x));
    }

    while (k--) {
      char c;
      cin >> c;
      if (c == 'C') {
        int i, v;
        cin >> i >> v;
        i--;
        sg.update(i, getx(v));
      } else {
        int i, j;
        cin >> i >> j;
        i--, j--;
        cout << getthis(sg.query(i, j));
      }
    }

    cout << endl;
  }

  return 0;
}
