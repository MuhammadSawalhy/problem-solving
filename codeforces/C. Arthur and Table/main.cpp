// ----------------------------------------------------------------------------
// Problem : C. Arthur and Table
// Author  : Muahmmad Assawalhy
// Date    : 15-09-22
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
  vector<T> count;
  bool updating = false;
  bool is_delta_update = false;
  function<T(T, T)> operation;
  T default_value;

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
      int query_high, T &v, T comulative_update = 0) {
    if (query_high >= node_high && query_low <= node_low) {
      if (updating) {
        tree[node] = v;
        updates[node] -= comulative_update;
        comulative_update = 0;
      }
      if (is_delta_update) {
        tree[node] += v; // consider for itself and parents
        updates[node] += v; // to consider for childern
      }
      return tree[node] + comulative_update;
    }

    if (query_high < node_low || node_high < query_low) {
      if (updating || is_delta_update)
        return tree[node] + comulative_update;
      else
        return default_value;
    }

    comulative_update += updates[node];

    int mid = (node_high + node_low) >> 1;
    const T &l = q(node << 1, node_low, mid, query_low, query_high, v, comulative_update);
    const T &r =
      q(node << 1 | 1, mid + 1, node_high, query_low, query_high, v, comulative_update);
    const T &val = operation(l, r);

    if (updating || is_delta_update)
      tree[node] = val;

    return val;
  }

  T query(int l, int r) {
    // default_value has nothing to do here, it is just a must to pass this argument
    l = get_correct_index(l);
    r = get_correct_index(r);
    T val = q(1, 0, n - 1, l, r, default_value);
    return val;
  }

  void u(int i, T val) {
    updating = true;
    q(1, 0, n - 1, i, i, val);
    updating = false;
  }

  void update(int i, T val) {
    i = get_correct_index(i);
    u(i, val);
  }

  void delta_update(int l, int r, T val) {
    is_delta_update = true;
    q(1, 0, n - 1, l, r, val);
    is_delta_update = false;
  }

  // You can't use delta_update with erase
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<pair<int, int>> l(n);
  vector<int> costs(n);

  for (int i = 0; i < n; i++) {
    cin >> l[i].first;
  }

  for (int i = 0; i < n; i++) {
    cin >> l[i].second;
    costs[i] = l[i].second;
  }

  sort(all(l), [&](auto &l, auto &r) {
    return l.first == r.first ? l.second > r.second : l.first > r.first;
  });

  sort(all(costs), greater<int>());

  segtree<int> segcosts(n);
  vector<bool> deleted(n);

  for (int i = 0; i < n; i++)
    segcosts.update(i, costs[i]);

  int c = 0;
  int ans = INT_MAX;

  int i = 0;
  while (true) {
    int y = 0;
    int cnt = 0;

    if (i < n) {
      int val = l[i].first;
      while (i < n && l[i].first == val) {
        // binary search for the NOT deleted "value", upper and lower bound
        int cost = l[i].second;
        int j = lower_bound(all(costs), cost, greater<int>()) - costs.begin();
        int k = upper_bound(all(costs), cost, greater<int>()) - costs.begin();
        for (; j < k; j++) {
          if (!deleted[j]) {
            // delete and break;
            segcosts.e(j);
            y += cost;
            cnt++;
            i++;
            deleted[j] = true;
            break;
          }
        }
      }
    }

    if (cnt == 0) { // i > n - 1
      break;
    }

    int x = 0;

    if (cnt - 1 < segcosts.count[1]) {
      // use segtrees to get the min value for x
      // I need to keep (cnt - 1) only
      x = segcosts.query(cnt - 1, segcosts.count[1] - 1);
    }

    ans = min(c + x, ans);
    c += y;
  }

  cout << ans << endl;
  return 0;
}
