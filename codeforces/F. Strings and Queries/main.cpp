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

  segtree(size_t n, T default_value = 0, function<T(T, T)> operation = [](T l, T r) { return l + r; })
  : default_value(default_value), operation(operation) {
    // Ceil it to the next pow of 2. Expected issue when "n" is
    // so huge that the next pow of 2 can't fit in 64 bits. This
    // is equivalent to: "pow(2, ceil(log(n)))"
    if (__builtin_popcountll(n) > 1)
      n = 1ull << (64 - __builtin_clzll(n));
    tree.assign(n << 1, default_value);
  }

  T q(size_t node, size_t node_low, size_t node_high, size_t query_low, size_t query_high, T &v) {
    if (query_high >= node_high && query_low <= node_low) {
      if (updating)
        tree[node] = v;
      return tree[node];
    }

    if (query_high < node_low || node_high < query_low) {
      return default_value;
    }

    size_t end_of_left = (node_high + node_low) >> 1;
    size_t lnode = node << 1, rnode = node << 1 | 1;
    q(lnode, node_low, end_of_left, query_low, query_high, v);
    q(rnode, end_of_left + 1, node_high, query_low, query_high, v);
    if (updating)
      tree[node] = operation(tree[lnode], tree[rnode]);

    return tree[node];
  }

  T query(size_t query_low, size_t query_high) {
    return q(1, 0, (tree.size() >> 1) - 1, query_low, query_high, default_value);
  }

  void update(size_t i, T val) {
    updating = true;
    q(1, 0, (tree.size() >> 1) - 1, i, i, val);
    updating = false;
  }
};

typedef segtree<pair<int, int>> segt;

int count_palin(string &s) {
  int cnt = 0;

  for (int i = 0; i < s.size(); i++) {
    int c = 1;
    for (int j = 1; j <= min(i, (int)s.size() - i - 1); j++) {
      if (s[i - j] != s[i + j]) break;
      c++;
    }
    cnt += c;
  }

  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] != s[i + 1]) continue;
    int c = 1;
    for (int j = 1; j <= min(i, (int)s.size() - i - 2); j++) {
      if (s[i - j] != s[i + j + 1]) break;
      c++;
    }
    cnt += c;
  }

  return cnt;
}

void solve() {
  int n, q;
  cin >> n >> q;

  segt sg(n, {0, 0}, [](auto l, auto r) {
    if (r.second > l.second)
      return r;
    else
      return l;
  });

  string s;
  map<string, int> strs;
  for (int i = 0; i < n; i++) {
    cin >> s;
    int cnt = count_palin(s);
    strs[s] = i;
    sg.update(i, {i + 1, cnt});
    debug(s, cnt, sg.tree);
  }


  while (q--) {
    string a, b;
    cin >> a >> b;
    int i = strs[a];
    int j = strs[b];
    if (i > j) swap(i, j);
    printf("%d\n", sg.query(i, j).first);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    solve();
  return 0;
}
