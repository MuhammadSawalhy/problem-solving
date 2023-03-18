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

void solve() {
  int n;
  cin >> n;
  vector<vi> adjmat = vector<vi>(n + 1, vi(n + 1, INT_MAX));

  vector<pair<int, int>> towns(n + 1);
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    towns[i] = {x, y};
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int dx = towns[i].first - towns[j].first;
      int dy = towns[i].second - towns[j].second;
      int d = dx * dx + dy * dy;
      adjmat[i][j] = d;
      adjmat[j][i] = d;
    }
  }

  int m;
  queue<int> qu;
  vb vis = vb(n + 1);
  bool flag;

  cin >> m;
  while (m--) {
    int i, j;
    cin >> i >> j;
    qu.push(i);
    qu.push(j);
    vis[i] = true;
    vis[j] = true;
  }

  if (qu.empty())
    qu.push(1);

  while (!qu.empty()) {
    int node = qu.front();
    qu.pop();

    int min = INT_MAX, j = -1;
    for (int i = 1; i <= n; i++) {
      int w = adjmat[node][i];
      if (!vis[i] && w < min) {
        min = w;
        j = i;
      }

      if (j != -1) {
        flag = true;
        cout << node << " " << j << endl;
        qu.push(j);
        vis[j] = true;
      }
    }
  }

  if (!flag)
    cout << "No new highways need" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_cases;
  cin >> t_cases;

  while (t_cases--) {
    solve();
    if (t_cases)
      cout << endl;
  }

  return 0;
}
