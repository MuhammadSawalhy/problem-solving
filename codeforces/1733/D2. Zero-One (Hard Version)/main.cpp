// ----------------------------------------------------------------------------
// Problem : D1. Zero-One (Easy Version)
// Author  : Muahmmad Assawalhy
// Date    : 19-09-22
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
  cin.tie(NULL), cout.tie(NULL);
  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--) {
    ll n, x, y;
    cin >> n >> x >> y;
    string a, b;
    cin >> a >> b;
    int a1 = 0, b1 = 0;

    vi ind;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i])
        ind.push_back(i);
    }

    if (ind.size() & 1) {
      cout << -1 << endl;
      continue;
    }

    ll adj = 0, cnt = 0;

    for (int i = 1; i < ind.size(); i++) {
      if (ind[i] == ind[i - 1] + 1) {
        adj++;
        i++;
      }
    }

    int i = 0, j = 0;
    int k = -1;
    vector<int> seg;
    while (true) {
      int a, b;
      while (i < ind.size() && ind[i] == -1)
        i++;
      if (i >= ind.size())
        break;
      a = ind[i];
      ind[i] = -1;
      while (j < ind.size() && ind[j] == -1)
        j++;
      if (j >= ind.size())
        break;
      b = ind[j];
      ind[j] = -1;

      if (k != -1)
        seg.push_back(a - k);
      seg.push_back(b - a);
      k = b;
      cnt++;
    }

    if (adj == 1 && ind.size() == 2) {
      // one pair adjacent pair
      cout << min(x, 2 * y) << endl;
      continue;
    }

    ll ans = cnt * y;

    ll memo[seg.size()][2];
    memset(memo, -1, sizeof memo);

    debug(n, seg);

    function<ll(int, bool)> maxdec = [&](int i, bool prev) -> ll {
      if (i >= seg.size())
        return 0LL;
      ll &m = memo[i][prev];
      if (m != -1)
        return m;
      m = maxdec(i + 1, false);
      if (!prev)
        m = max(m, maxdec(i + 1, true) + (y - seg[i] * x));
      return m;
    };

    ans -= maxdec(0, false);
    cout << ans << endl;
  }
  return 0;
}
