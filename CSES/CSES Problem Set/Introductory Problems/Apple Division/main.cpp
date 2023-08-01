// ﷽
// 10 جُمادى الآخرة 1444
// Jan 02, 2023
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
    ll a[n];
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    // brute force all
    
    ll ans = 1e9;
    for (int i = 0; i < 1 << n; i++) {
        ll s = 0;
        for (int j = 0; j < n; j++) {
            s += ((i >> j) & 1) * a[j];
        }
        ans = min(ans, abs(sum - s * 2));
    }

    cout << ans;

    return 0;
}
