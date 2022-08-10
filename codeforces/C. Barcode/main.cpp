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

int n, m, x, y;
vector<array<int, 2>> costs; // costs to turn to the desired color
vector<map<int, int>> memo;
enum color { black, white };

int getmin(int col, int prevlen, color prevcolor) {
  if (col >= m)
    return 0;
  const int memokey = prevlen << (prevcolor * 10);
  if (memo[col].find(memokey) != memo[col].end())
    return memo[col][memokey];
  int &val = memo[col][memokey];
  val = LONG_LONG_MAX - m;

  if (prevlen < y) {
    color newcolor = prevcolor;
    int cost = costs[col][newcolor];
    cost += getmin(col + 1, prevlen + 1, newcolor);
    val = min(val, cost);
  }

  if (m - col >= x && prevlen >= x) {
    color newcolor = prevcolor == white ? black : white;
    int cost = costs[col][newcolor];
    cost += getmin(col + 1, 1, newcolor);
    val = min(val, cost);
  }

  return val;
}

void solve() {
  cin >> n >> m >> x >> y;
  costs = vector<array<int, 2>>(m);
  memo = vector<map<int, int>>(m);
  string row;
  for (int i = 0; i < n; i++) {
    cin >> row;
    for (int j = 0; j < m; j++) {
      if (row[j] == '.')
        costs[j][black]++;
      if (row[j] == '#')
        costs[j][white]++;
    }
  }

  int ans = min(costs[0][black] + getmin(1, 1, black),
                costs[0][white] + getmin(1, 1, white));
  cout << ans << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
