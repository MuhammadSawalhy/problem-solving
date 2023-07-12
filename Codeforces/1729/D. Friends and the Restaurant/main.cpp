// ----------------------------------------------------------------------------
// Problem : D. Friends and the Restaurant
// Author  : Muahmmad Assawalhy
// Date    : 12-09-22
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
  cin.tie(NULL);
  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--) {
    int n;
    cin >> n;
    vector<long long> x(n);
    vector<long long> y(n);
    for (int i = 0 ;i < n; i++) {
      cin >> x[i];
    }
    for (int i = 0 ;i < n; i++) {
      cin >> y[i];
      y[i] -= x[i];
    }

    sort(all(y));
    int i = 0, j = n - 1;
    int ans = 0;

    while (i < j) {
      while (i < j && y[i] + y[j] < 0) {
        i++;
      }
    
      if (i == j)
        break;
      
      j--;
      i++;
      ans++;
    }
    
    cout << ans << endl;
  }
  return 0;
}
