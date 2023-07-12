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
  int n, x;
  cin >> n >> x;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int xx = 0;
  int k;
  cin >> k;
  while (k--) {
    int b;
    cin >> b;
    xx += a[b - 1];
  }

  debug_itr(a, a + n);
  debug(x, xx);

  cout << x - xx + 1 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
