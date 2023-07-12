// Date: 09-10-2022
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#endif

struct union_find {
  vector<int> rank, parent;
  int forests;

  union_find(int n) {
    forests = n;
    rank = vector<int>(n);
    parent = vector<int>(n);
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }

  bool connected(int x, int y) { return find(x) == find(y); }

  int find(int x) {
    if (parent[x] == x)
      return x;
    return parent[x] = find(parent[x]);
  }

  bool uni(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)
      return false;
    if (rank[y] > rank[x])
      swap(x, y);
    parent[y] = x;
    if (rank[x] == rank[y])
      rank[x]++;
    return true;
  }
};

int n;

void solve() {
  int a[n], b[n];
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i];

  auto valid = [&](double m) -> bool {
    union_find uf(n);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int dx = a[i] - a[j], dy = b[i] - b[j];
        bool reachable = dx * dx + dy * dy <= m * m;
        if (reachable) {
          uf.uni(i, j);
        }
      }
    }

    return uf.connected(0, 1);
  };

  double s = 0, e = 1e6;
  while (e - s > 1e-4) {
    double mid = (s + e) / 2;
    if (valid(mid)) {
      e = mid;
    } else {
      s = mid;
    }
  }

  cout << "Frog Distance = " << s << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cout << fixed << setprecision(3);
  int t = 0;
  while (cin >> n, n) {
    cout << "Scenario #" << ++t << endl;
    solve();
    cout << endl;
  }

  return 0;
}
