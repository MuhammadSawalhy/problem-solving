// Date: 01-01-2023
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    ll a[n + 1];
    ll ans = 0;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ll inc = max(0LL, a[i - 1] - a[i]);
        a[i] += inc;
        ans += inc;
    }

    cout << ans << endl;

    return 0;
}
