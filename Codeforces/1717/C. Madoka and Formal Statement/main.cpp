//============================================================================
// Problem     : C. Madoka and Formal Statement
// Author      : Muahmmad Assawalhy
// Date        : 02-09-22
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
  int n;
  cin >> n;
  vi a(n);
  vi b(n);
  for (auto &i : a)
    cin >> i;
  for (auto &i : b)
    cin >> i;

  for (int i = n - 1; i >= 0; i--) {
    a[i] = max(a[i], min(a[(i + 1) % n], b[i]));
  }

  for (int i = n - 1; i >= 0; i--) {
    a[i] = max(a[i], min(a[(i + 1) % n], b[i]));
  }

  for (int i = 0; i < n; i++) {
    b[i] -= a[i];
  }

  for (int i = 0; i < n; i++) {
    if (b[i] < 0 ||
        (b[i] > 0 && b[i] + a[i] - (b[(i + 1) % n] + a[(i + 1) % n]) > 1)) {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--)
    solve();
  return 0;
}
