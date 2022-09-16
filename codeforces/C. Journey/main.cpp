//============================================================================
// Problem     : C. Journey
// Author      : Muahmmad Assawalhy
// Date        : 01-09-22
//============================================================================

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

vector<vector<int>> adjlist;
vector<bool> vis;

double expected(int node) {
  double e = 0;
  vis[node] = true;

  for (int n : adjlist[node])
    if (!vis[n])
      e += (1 + expected(n)) / (double)(adjlist[node].size() - (node != 1));

  debug(node, e);
  return e;
}

void solve() {
  int n;
  cin >> n;
  vis.resize(n + 1);
  adjlist.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
  }

  debug(adjlist);

  cout << fixed << setprecision(15) << expected(1) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
