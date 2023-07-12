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

#define int ll
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()
#define sum(v) accumulate(all(v), 0)

int n, m;
vector<vector<set<int>>> adjmat;
vector<bool> vis;

int dfs(int u, int v, int c) {
  vis[u] = true;
  if (u == v)
    return 1;

  int ans = 0;

  for (int i = 1; i <= n; i++) {
    auto &edges = adjmat[u][i];
    if (edges.find(c) != edges.end()) {
      if (!vis[i])
        ans += dfs(i, v, c);
    }
  }

  return ans;
}

void solve() {
  cin >> n >> m;
  adjmat = vector<vector<set<int>>>(n + 1, vector<set<int>>(n + 1));

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adjmat[a][b].insert(c);
    adjmat[b][a].insert(c);
  }

  debug(adjmat);

  int q;
  cin >> q;
  while (q--) {
    int ans = 0;
    int u, v;
    cin >> u >> v;
    debug(u, v);
    for (int c = 1; c <= m; c++) {
      vis = vector<bool>(n + 1);
      ans += dfs(u, v, c);
      debug(c, ans);
    }
    std::cout << ans << std::endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
