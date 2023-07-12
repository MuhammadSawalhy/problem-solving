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

int n, k;
int a[3000];
int poss[3001];

void solve() {
  cin >> n >> k;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = INT_MAX;
  // a is sorted and this helped us, so we will take a[0]
  for (int v = 1; v <= a[0]; v++) {
    int m = 0;
    for (int i = 0; i < n; i++) {
      int p = min(k, a[i] / v);
      m = max(m, a[i] / p);
    }

    ans = min(ans, m - v);
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
