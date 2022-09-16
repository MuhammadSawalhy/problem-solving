//============================================================================
// Problem     : E. Counting Rectangles
// Author      : Muahmmad Assawalhy
// Date        : 31-08-22
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

void solve() {
  int n, q;
  cin >> n >> q;

  const int N = 1001;
  vector<vector<ll>> rects(N, vector<ll>(N));
  for (int i = 0; i < n; i++) {
    int h, w;
    cin >> h >> w;
    rects[w][h] += h * w;
  }

  for (int i = 1; i < N; i++) {
    for (int j = 1; j < N; j++) {
      rects[i][j] += rects[i - 1][j];
      rects[i][j] += rects[i][j - 1];
      rects[i][j] -= rects[i - 1][j - 1];
    }
  }

  while (q--) {
    int h, w, hh, ww;
    cin >> h >> w >> hh >> ww;

    ll ans = rects[ww - 1][hh - 1];
    ans -= rects[ww - 1][h];
    ans -= rects[w][hh - 1];
    ans += rects[w][h];
    cout << ans << endl;
  }
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
