// ----------------------------------------------------------------------------
// Problem : C. Parity Shuffle Sorting
// Author  : Muahmmad Assawalhy
// Date    : 19-09-22
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
  cin.tie(NULL), cout.tie(NULL);
  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--) {
    int n;
    cin >> n;
    vi a(n);
    for (int &i : a)
      cin >> i;

    vector<pair<int, int>> ans;
    if ((a[0] ^ a[n - 1]) & 1) {
      a[n - 1] = a[0];
      ans.push_back({1, n});
    } else if (a[0] != a[n - 1]) {
      a[0] = a[n - 1];
      ans.push_back({1, n});
    }

    for (int i = 1; i < n - 1; i++) {
      if ((a[0] ^ a[i]) & 1) {
        a[i] = a[0];
        ans.push_back({1, i + 1});
      } else if (a[0] != a[i]) {
        a[i] = a[n - 1];
        ans.push_back({i + 1, n});
      }
    }

    cout << ans.size() << endl;
    for (auto [l, r] : ans)
      cout << l << " " << r << endl;
  }
  return 0;
}
