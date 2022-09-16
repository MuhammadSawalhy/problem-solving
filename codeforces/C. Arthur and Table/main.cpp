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
  size_t n;
  vector<T> tree;
  bool updating;
  T default_value;
  function<T(T, T)> operation;

  segtree(size_t n, T default_value = 0, function<T(T, T)> operation = [](T l, T r) { return l + r; }) {
    // Ceil it to the next pow of 2. Expected issue when "n" is
    // so huge that the next pow of 2 can't fit in 64 bits. This
    // is equivalent to: "pow(2, ceil(log(n)))"
    if (__builtin_popcountll(n) > 1)
      n = 1ull << (64 - __builtin_clzll(n));
    this->n = n;
    this->operation = operation;
    this->default_value = default_value;
    tree.assign(n << 1, default_value);
  }

  segtree(vector<T> &v, T default_value = 0, function<T(T, T)> operation = [](T l, T r) { return l + r; }) {
    // Ceil it to the next pow of 2. Expected issue when "n" is
    // so huge that the next pow of 2 can't fit in 64 bits. This
    // is equivalent to: "pow(2, ceil(log(n)))"
    segtree(v.size(), default_value, operation);
    for (size_t i = 0; i < v.size(); i++) {
      update(i, v[i]);
    }
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
        return default_value;
    }

    size_t end_of_left = (node_high + node_low) >> 1;
    const T &l = q(node << 1, node_low, end_of_left, query_low, query_high, v);
    const T &r =
        q(node << 1 | 1, end_of_left + 1, node_high, query_low, query_high, v);
    const T &val = operation(l, r);

    if (updating)
      tree[node] = val;

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
  segtree<int> segcount(n);
  vector<bool> deleted(n);

  for (int i = 0; i < n; i++)
    segcosts.update(i, costs[i]);

  for (int i = 0; i < n; i++)
    segcount.update(i, 1);

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
            segcosts.update(j, 0);
            segcount.update(j, 0);
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

    if (i + cnt - 1 < n) {
      // use segtrees to get the min value for x
      // I need to keep (cnt - 1) only
      int j = segcount.search(segcount.tree[1] - (cnt - 1));
      x = segcosts.query(j, n - 1);
      debug(j);
      debug(segcount.tree);
    }

    ans = min(c + x, ans);
    c += y;
  }

  cout << ans << endl;
  return 0;
}
