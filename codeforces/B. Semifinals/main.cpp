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

  array<vector<bool>, 2> r({vector<bool>(n), vector<bool>(n)});
  vector<array<int, 3>> p(2 * n);

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    p[i * 2] = {0, i, a};
    p[i * 2 + 1] = {1, i, b};
  }

  for (int k : {0, n / 2}) {
    debug(k);
    sort(all(p), [&k](auto l, auto r) {
      if (l[1] >= k && r[1] >= k)
        return r[2] > l[2];
      return l[1] < k && r[1] >= k;
    });

    for (int i = 0; i < n; i++) {
      r[p[i][0]][p[i][1]] = true;
    }
  }

  for (int i = 0; i < n; i++)
    cout << r[0][i];
  cout << endl;
  for (int i = 0; i < n; i++)
    cout << r[1][i];
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
