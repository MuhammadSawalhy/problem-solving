// Date: 05-10-22
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

template <class T>
void choose(int cnt, vector<T> &v, vector<vector<T>> &res, int i = 0,
            vector<T> choosen = vector<T>()) {

  if (cnt == 0) {
    res.push_back(choosen);
    return;
  }

  if (i >= (int)v.size())
    return;

  choosen.push_back(v[i]);
  choose(cnt - 1, v, res, i + 1, choosen);
  choosen.pop_back();
  choose(cnt, v, res, i + 1, choosen);
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> parents(n);
  for (int i = 1; i < n; i++)
    cin >> parents[i], parents[i]--;
  vector<int> nodes(n - 1);
  iota(nodes.begin(), nodes.end(), 1);

  vector<vector<int>> to_move;
  choose(k, nodes, to_move);

  vector<int> p;
  auto calc = [&]() {
    vector<vector<int>> adjlist(n);
    for (int i = 1; i < n; i++) {
      adjlist[p[i]].push_back(i);
    }

    function<int(int)> calc_d = [&](int node) -> int {
      int d = 0;
      for (auto child : adjlist[node])
        d = max(calc_d(child) + 1, d);
      return d;
    };
    
    return calc_d(0);
  };

  int ans = 1e6;
  for (auto m : to_move) {
    p = parents;
    for (auto node : m) {
      p[node] = 0;
    }
    ans = min(ans, calc());
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
