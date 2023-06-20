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
    sort(a, a+ n );

    ll cost = 0;
    for (int i  = 0, j = n - 1; i < j; i ++ , j--) 
      cost += a[j] - a[i];

    cout << cost << '\n';
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
