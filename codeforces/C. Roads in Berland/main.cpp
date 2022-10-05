// Date: 22-09-22
#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

constexpr int N = 300;

vector<long long> dist(300, LONG_LONG_MAX);
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>>
    qu;
long long dijkstra(int s, vector<vector<int>> &mat) {
  fill(dist.begin(), dist.begin() + mat.size(), LONG_LONG_MAX);
  dist[s] = 0;
  qu.push({0, s});
  while (!qu.empty()) {
    auto [d, c] = qu.top();
    qu.pop();

    if (d > dist[c])
      continue;
    for (int i = 0; i < (int)mat.size(); i++) {
      if (c == i)
        continue;
      if (d + mat[c][i] < dist[i]) {
        qu.push({d + mat[c][i], i});
        dist[i] = d + mat[c][i];
      }
    }
  }

  debug(dist);

  long long res = 0;
  for (int i = 0; i < (int)mat.size(); i++)
    res += dist[i];
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  vector<vector<int>> mat(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
    }
  }

  int k;
  cin >> k;
  long long ans = 0;

  while (k--) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;

    if (c >= mat[a][b] && ans != 0) {
      cout << ans << endl;
      continue;
    }

    mat[a][b] = c;
    mat[b][a] = c;

    ans = 0;
    for (int i = 0; i < n; i++) {
      ans += dijkstra(i, mat);
    }
    ans >>= 1;

    cout << ans << " ";
  }

  return 0;
}
