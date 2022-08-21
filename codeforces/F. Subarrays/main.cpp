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
  int n, k;
  cin >> n >> k;

  int a[n + 1];
  int s[n + 1];

  s[0] = 0;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = a[i] + s[i - 1];
    s[i] %= k;
  }

  map<int, int> f;
  ull ans = 0;
  f[0] = 1;

  for (int i = 1; i <= n; i++) {
    ans += f[s[i]];
    f[s[i]]++;
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
