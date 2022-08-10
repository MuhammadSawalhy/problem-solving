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

int mod(int n, int k) {
  int m = n % k;
  while (m < 0)
    m = (m + k) % k;
  return m;
}

void solve() {
  int n;
  cin >> n;
  vi a(n);
  for (auto &i : a)
    cin >> i;
  debug(n, a);
  for (int i = 0; i < n; i++) {
    int j;
    string moves;
    cin >> j;
    cin >> moves;
    debug(moves);
    for (int j = 0; j < sz(moves); j++) {
      if (moves[j] == 'U')
        a[i]--;
      if (moves[j] == 'D')
        a[i]++;
    }

    a[i] = mod(a[i], 10);
  }

  for (int i = 0; i < n; i++)
    cout << a[i] << " \n"[i == n - 1];
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
