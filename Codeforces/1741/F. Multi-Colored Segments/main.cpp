// Date: 14-10-2022
#include <bits/stdc++.h>

#define debug(...)
#define ll long long
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

using namespace std;
constexpr ll inf = 1e9 + 7;

// clang-format off
template <typename T> struct segtree {
  int n;
  vector<T> tree;
  vector<ll> updates;
  vector<ll> applied_updates;
  vector<ll> count;
  bool updating = false;
  bool is_delta_update = false;
  ll update_value;
  T default_value;
  function<T(T, T)> operation;
  function<void(int, ll)> delta_update_node = [](int node, ll delta) {};
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
    updates.assign(n << 1, default_value);
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
      int query_high, ll comulative_update) {

    comulative_update = operation(updates[node], comulative_update);

    if (query_high >= node_high && query_low <= node_low) {
      if (updating) {
        tree[node] = update_value;
        comulative_update = operation(comulative_update, update_value); // consider for himself now
      }
      if (is_delta_update) {
        updates[node] = operation(updates[node], update_value); // to consider for childern in the future
        comulative_update = operation(comulative_update, update_value); // consider for himself now
      }
      delta_update_node(node, comulative_update);
      return tree[node];
    }

    if (query_high < node_low || node_high < query_low) {
      if (updating || is_delta_update) {
        delta_update_node(node, comulative_update);
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
      tree[node] = operation(val, tree[node]);
      // don't consider my comulative_update as my left and right did this already
      // applied_updates[node] = comulative_update;
    }

    return val;
  }

  T query(int l, int r) {
    l = get_correct_index(l);
    r = get_correct_index(r);
    T val = q(1, 0, n - 1, l, r, default_value);
    return val;
  }

  void u(int i, ll val) {
    updating = true;
    update_value = val;
    q(1, 0, n - 1, i, i);
    updating = false;
  }

  void update(int i, ll val) {
    i = get_correct_index(i);
    u(i, val);
  }

  void delta_update(int l, int r, ll val) {
    is_delta_update = true;
    update_value = val;
    q(1, 0, n - 1, l, r, default_value);
    is_delta_update = false;
  }

  void update_range(int l, int r, ll val) {

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

int n;
enum e { L, R };

vector<ll> calc(vector<array<ll, 5>> edges) {
  segtree<ll> sg(n, -inf, [](auto l, auto r) { return max(l, r); });
  sg.delta_update_node = [&sg](int node, ll val) {
    sg.tree[node] = max(sg.tree[node], val);
  };
  vector<ll> res(n, inf);

  sort(edges.begin(), edges.end());

  for (int i = 0; i < 2 * n; i++) {
    if (edges[i][2] == R) {
      ll mx = sg.query(edges[i][3], edges[i][3]);
      res[edges[i][4]] = min(res[edges[i][4]], max(0LL, edges[i][1] - mx));
    } else {
      if (edges[i][3] > 0) {
        sg.delta_update(0, edges[i][3] - 1, edges[i][1]);
      }
      if (edges[i][3] < n - 1) {
        sg.delta_update(edges[i][3] + 1, n - 1, edges[i][1]);
      }
    }
  }

  return res;
}

void solve() {
  cin >> n;

  vector<array<ll, 5>> a, b;
  vector<int> color(n);

  for (int i = 0; i < n; i++) {
    int l, r, c;
    cin >> l >> r >> c;
    color[i] = --c;

    a.push_back({l, r, L, c, i});
    a.push_back({r, l, R, c, i});
    // reflect about y = inf
    b.push_back({inf - l, inf - r, R, c, i}); // left becomes right
    b.push_back({inf - r, inf - l, L, c, i}); // right becomes left
  }

  auto aa = calc(a);
  auto bb = calc(b);

  for (int i = 0; i < n; i++)
    cout << min(aa[i], bb[i]) << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
