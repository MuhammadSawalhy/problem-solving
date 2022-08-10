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

vi numofnodes;
vector<vi> adjlist;

int calcit(int node, vector<bool> &vis) {
  debug(node);
  vis[node] = true;

  int res = 0;

  for (int child : adjlist[node]) {
    if (!vis[child]) {
      int childres = numofnodes[child];

      for (int c : adjlist[node]) {
        if (!vis[c] && child != c) {
          childres += calcit(c, vis);
        }
      }

      res = max(res, childres);
    }
  }

  vis[node] = false;
  debug(node, res);
  return res;
}

int count(int node, vector<bool> &vis) {
  vis[node] = true;

  int c = 0;

  for (int child : adjlist[node]) {
    if (!vis[child])
      c += 1 + count(child, vis);
  }

  numofnodes[node] = c;
  return c;
}

// because it is the root that is infected, it is an easy problem
void solve() {
  int n;
  cin >> n;

  vi parents(n + 1);
  numofnodes = vi(n + 1);
  adjlist = vector<vi>(n + 1);

  for (int i = 1; i <= n - 1; i++) {
    int p, c;
    cin >> p >> c;
    adjlist[p].push_back(c);
    adjlist[c].push_back(p);
  }

  const int ROOT = 1;

  vector<bool> vis;
  vis = vector<bool>(n + 1);
  count(ROOT, vis);

  debug(adjlist);
  debug(numofnodes);

  vis = vector<bool>(n + 1);
  std::cout << calcit(ROOT, vis) << std::endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_case;
  cin >> t_case;
  while (t_case--)
    solve();
  return 0;
}
