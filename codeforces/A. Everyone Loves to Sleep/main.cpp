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
  int n, h, m;
  cin >> n >> h >> m;

  int t = h * 60 + m;
  int ans = INT_MAX;

  while (n--) {
    cin >> h >> m;
    int tt = h * 60 + m;
    if (tt < t)
      tt += 24 * 60;
    ans = min(ans, tt - t);
  }

  cout << ans / 60 << ' ' << ans % 60 << endl;
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
