// Date: 26-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

void solve() {
  int n;
  cin >> n;
  ll a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll g = a[0];

  // when we have x and y with gcd(x, y) == 1
  // |x - y| is guarentee to be less than the smallest
  // or between the smallest and the maximum
  //
  // and this new value will have gcd of 1 with both of x and y
  // gcd(x, |x - y|) == gcd(y, |x - y|) == 1
  // we can subtract until we get 1
  //
  // but what about three numbers? e.g.: 10, 6, 15 with gcd of 1
  // 6 and 15 will result in 3 at the end
  // 10 and 6 will result in 2 at the end
  // now take 2, 3 and repeat the process you will get 1

  for (int i = 1; i < n; i++)
    g = gcd(g, a[i]);
  cout << a[n - 1] / g << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
