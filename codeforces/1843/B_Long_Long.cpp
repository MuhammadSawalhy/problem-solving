// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

void solve() {
    
    int n; cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    cin >> a[i];

    bool state = 1;
    int ops = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += abs(a[i]);

      if (a[i] < 0 && state == 1) {
        ops++;
      }

      if (a[i] < 0) state = 0;
      else if (a[i] > 0) state = 1;
    }

    cout << sum << ' ' << ops << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
