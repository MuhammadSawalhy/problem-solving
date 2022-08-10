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

int n;
int a[2000];

void solve() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  if (n == 2) {
    n = 3;
    a[2] = 0;
  }

  for (int i = n - 2; i >= 2; i--) {
    a[i] ^= a[i + 1];
  }

  if ((a[0] ^ a[1]) == a[2] || (a[0] == a[1] && a[0] == a[2]))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
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
