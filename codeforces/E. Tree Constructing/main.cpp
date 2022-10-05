// Date: 04-10-22
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

int cnt = 0;
vector<pair<int, int>> edges;
int n, d, k;

void build_dia(int depth) {
  cnt++;
  if (depth == d) {
    return;
  }
  edges.push_back({cnt - 1, cnt});
  build_dia(depth + 1);
}

void complete(int i, int depth, bool topline = true) {
  if (depth == d || edges.size() == n - 1) {
    // we should stop
    return;
  }

  // we already have an edges from the parent
  for (int j = 0; j < k - (topline ? 2 : 1); j++) {
    if ((topline ? max(depth, d - depth) : depth) == d || edges.size() == n - 1)
      break;
    edges.push_back({i, cnt++});
    // go to the child
    complete(cnt - 1, (topline ? max(depth, d - depth) : depth) + 1, false);
  }

  if (topline)
    complete(i + 1, depth + 1, topline);
}

void solve() {
  cin >> n >> d >> k;

  if (d > n - 1 || k == 1 && d > 1) {
    cout << "NO" << endl;
    return;
  }

  build_dia(0);
  complete(0, 0);

  if (edges.size() != n - 1) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  for (auto [u, v] : edges) {
    cout << u + 1 << " " << v + 1 << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  solve();
  return 0;
}
