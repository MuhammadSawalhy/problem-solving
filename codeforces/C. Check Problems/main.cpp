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
  ull a[n];
  ull d[n];
  ull c[n];

  c[0] = 0;
  a[0] = 0;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i > 0) {
      d[i - 1] = a[i] - a[i - 1];
      if (i > 1)
        c[i - 1] = d[i - 1] + c[i - 2];
      else
        c[i - 1] = d[i - 1];
    }
  }

  d[n - 1] = ULONG_LONG_MAX;

  int q;
  cin >> q;
  while (q--) {
    ull t;
    cin >> t;
    int i = upper_bound(d, d + n, t) - d;
    ull ans = 0;
    ans += (ull)(n - i) * (ull)t;
    if (i > 0)
      ans += c[i - 1];
    cout << ans << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
