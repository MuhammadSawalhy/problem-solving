// Date: 01-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

// clang-format off
template <typename T> struct Node {
  T value = 0;
  T relative_update = make_pair(0, 0);
  bool pending_update = false;
  Node(){};
  Node(T value) : value(value){};

  void update(T &val) {
    value = val;
    relative_update = {0, 0};
    pending_update = true;
  }

  void accumulate_rel(T rel) {
    if (rel.first > relative_update.first)
      relative_update = rel;
    else if (rel.first == relative_update.first) {
      if (rel.second > relative_update.second)
        relative_update = rel;
    }
  }

  void relupdate(T &val) {
    relative_update = val;
  }

  void propagate(int node, vector<Node<T>> &tree) {
    int left = node << 1, right = node << 1 | 1;
    int sz = tree.size();

    if (pending_update) {
      if (left < sz) {
        tree[left].value = value;
        tree[left].relative_update = {0, 0};
        tree[left].pending_update = true;
      }
      if (right < sz) {
        tree[right].value = value;
        tree[right].relative_update = {0, 0};
        tree[right].pending_update = true;
      }
      pending_update = false;
    }

    if (value.first < relative_update.first)
      value = relative_update;
    else if (value.first == relative_update.first) {
      if (value.second > relative_update.second)
        value = relative_update;
    }

    if (left < sz) {
      if (tree[left].relative_update.first < relative_update.first)
        tree[left].relative_update = relative_update;
      else if (tree[left].relative_update.first == relative_update.first) {
        if (tree[left].relative_update.second > relative_update.second)
          tree[left].relative_update = relative_update;
      }
    }
    if (right < sz) {
      if (tree[right].relative_update.first < relative_update.first)
        tree[right].relative_update = relative_update;
      else if (tree[right].relative_update.first == relative_update.first) {
        if (tree[right].relative_update.second > relative_update.second)
          tree[right].relative_update = relative_update;
      }
    }
    relative_update = {0, 0};
  }
};

template<class T>
ostream& operator<<(ostream &cout, const Node<T> &n) {
  cout << "(" << n.value.first << ", " << n.value.second << ")";
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

  void relative_update(int i, int j, T val) {
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
// clang-format on

void solve() {
  int n;
  cin >> n;

  unsigned ll a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i], b[i] = a[i];
  }

  sort(b, b + n);
  map<unsigned ll, int> mapper;
  map<int, unsigned ll> rev;
  for (int i = 0; i < n; i++) {
    mapper[b[i]] = i + 1;
    rev[i + 1] = b[i];
  }

  for (int i = 0; i < n; i++) {
    a[i] = mapper[a[i]];
  }

  segtree<pair<int, int>> sg(n + 4, {0, 0}, [](auto l, auto r) {
    if (l.first == 0)
      return r;
    return l;
  });

  for (int i = 0; i < n; i++) {
    sg.update(a[i], {1, a[i]});
  }

  unsigned ll ans = 0;
  int maxlen = 0;
  for (int i = 0; i < n; i++) {
    auto [length, tail] = sg.query(a[i], a[i]);
    // debug(a[i], length, tail);
    if (length > maxlen) {
      maxlen = length;
      ans = rev[a[i]] - rev[tail];
    } else if (length == maxlen) {
      ans = max(rev[a[i]] - rev[tail], ans);
    }
    sg.relative_update(a[i] + 1, n, {length + 1, tail});
  }

  cout << ans << endl;
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
