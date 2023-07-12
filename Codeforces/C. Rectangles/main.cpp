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
  bool grid[101][101];
  memset(grid, 0, sizeof(grid));
  int i, j, k;
  int ans = 0;
  while (n--) {
    cin >> i >> j >> k;
    for (int x = i; x < j; x++) {
      for (int y = 0; y < k; y++) {
        if (!grid[x][y])
          ans++;
        grid[x][y] = true;
      }
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_cases;
  cin >> t_cases;
  while (t_cases--)
    solve();
  return 0;
}
