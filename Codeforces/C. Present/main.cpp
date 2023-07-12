// Date: 25-09-22
#include <bits/stdc++.h>
#define ll long long
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

// clang-format off
template <typename T> struct Node {
  T value = 0;
  ll relative_update = 0;
  bool pending_update = false;
  Node(){};
  Node(T value) : value(value){};

  void update(T &val) {
    value = val;
    relative_update = 0;
    pending_update = true;
  }

  void relupdate(T &val) {
    relative_update += val;
  }

  void propagate(int node, vector<Node<T>> &tree) {
    int left = node << 1, right = node << 1 | 1;
    int sz = tree.size();

    if (pending_update) {
      if (left < sz) {
        tree[left].value = value;
        tree[left].relative_update = 0;
        tree[left].pending_update = true;
      }
      if (right < sz) {
        tree[right].value = value;
        tree[right].relative_update = 0;
        tree[right].pending_update = true;
      }
      pending_update = false;
    }

    value.first += relative_update;
    if (left < sz)
      tree[left].relative_update += relative_update;
    if (right < sz)
      tree[right].relative_update += relative_update;
    relative_update = 0;
  }
};

template<class T>
ostream& operator<<(ostream &cout, const Node<T> &n) {
  cout << "(value: " << n.value << ", rel: " << n.relative_update << ")";
  return cout;
}

template <typename T> struct segtree {
  int n;
  T default_value;
  vector<Node<T>> tree;
  function<T(T, T)> operation;

  segtree(
      int n, T default_value,
      function<T(T, T)> operation = [](T l, T r) { return l + r; }) {
    int _n = n;
    if (__builtin_popcountll(n) > 1)
      n = 1 << (64 - __builtin_clzll(n));
    this->n = n;
    this->operation = operation;
    this->default_value = default_value;
    tree.assign(n << 1, default_value);
  }

  T query(int l, int r) {
    return query(1, 0, n - 1, l, r);
  }

  void update(int i, int j, T val) {
    update(1, 0, n - 1, i, j, val);
  }

  void update(int i, T val) {
    update(i, i, val);
  }

  void relative_update(int i, int j, ll val) {
    relative_update(1, 0, n - 1, i, j, val);
  }

private:
  T query(int node, int node_low, int node_high, int query_low, int query_high) {
    tree[node].propagate(node, tree);
    if (query_high >= node_high && query_low <= node_low) return tree[node].value;
    if (query_high < node_low || node_high < query_low) return default_value;

    int mid = (node_high + node_low) >> 1;
    const T &l = query(node << 1, node_low, mid, query_low, query_high);
    const T &r = query(node << 1 | 1, mid + 1, node_high, query_low, query_high);

    return operation(l, r);
  }

  void update(int node, int node_low, int node_high,
           int query_low, int query_high, T &val) {
    tree[node].propagate(node, tree);
    if (query_high < node_low || node_high < query_low) return;
    if (query_high >= node_high && query_low <= node_low) {
      tree[node].update(val);
      tree[node].propagate(node, tree);
      return;
    }

    int mid = (node_high + node_low) >> 1;
    update(node << 1, node_low, mid, query_low, query_high, val);
    update(node << 1 | 1, mid + 1, node_high, query_low, query_high, val);
    tree[node] = operation(tree[node << 1].value, tree[node << 1 | 1].value);
  }

  void relative_update(int node, int node_low, int node_high,
           int query_low, int query_high, T &val) {
    tree[node].propagate(node, tree);
    if (query_high < node_low || node_high < query_low) return;
    if (query_high >= node_high && query_low <= node_low) {
      tree[node].relupdate(val);
      tree[node].propagate(node, tree);
      return;
    }

    int mid = (node_high + node_low) >> 1;
    relative_update(node << 1, node_low, mid, query_low, query_high, val);
    relative_update(node << 1 | 1, mid + 1, node_high, query_low, query_high, val);
    tree[node] = operation(tree[node << 1].value, tree[node << 1 | 1].value);
  }
};

segtree<ll> sum_segtree(int n) {
  segtree<ll> sg(n, 0, [](ll l, ll r) { return l + r; });
  return sg;
}

segtree<ll> max_segtree(int n) {
  segtree<ll> sg(n, LONG_LONG_MIN, [](ll l, ll r) { return max(l, r); });
  return sg;
}

segtree<ll> min_segtree(int n) {
  segtree<ll> sg(n, LONG_LONG_MAX, [](ll l, ll r) { return min(l, r); });
  return sg;
}
// clang-format on

void solve() {
  int n, m, w;
  cin >> n >> m >> w;
  segtree<pair<long long, int>> a(n, {LONG_LONG_MAX, -1}, [](auto l, auto r) {
    return l.first <= r.first ? l : r;
  });

  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    a.update(i, {b, i});
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

    a.relative_update(i, j, 1LL);
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
