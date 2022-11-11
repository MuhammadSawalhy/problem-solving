// ----------------------------------------------------------------------------
// Problem : D. Dima and Bacteria
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, k;
  vector<int> c(k);
  cin >> n >> m >> k;

  for (int i = 0; i < k; i++)
    cin >> c[i];

  vector<int> type(n);

  int cnt;
  int t = 0;
  for (int i = 0; i < n; i++) {
    if (c[t] == cnt) {
      t++;
      cnt = 0;
    }
    type[i] = t;
    cnt++;
  }

  vector<vector<int>> sp(n, vector<int>(k, 1e9));

  for (int i = 0; i < n; i++) {
    sp[i][type[i]] = 0;
  }

  while (m--) {
    int u, v, x;
    cin >> u >> v >> x;
    u--, v--;
    // connect them
    for (int i = 0; i < k; i++) {
      sp[u][i] = min(sp[u][i], sp[v][i] + x);
      sp[v][i] = min(sp[v][i], sp[v][i] + x);
    }
  }

  vector<vector<int>> ans(k, vector<int>(k));
  for (int i = 0; i < k; i++) {
    for (int j = i + 1; j < k; j++) {
    }
  }

  cout << "Yes" << endl;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
