// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

void solve() {
    int n; cin >> n; ll a[n + 1];
    ll sum = 0;
    for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];

    
    ll s = a[0];
    ll ans = 1;
    for (int i = 1; i < n; i++) {
        ll r = sum - s;
        ans = max(ans, gcd(r, s));
        s += a[i];
    }
    cout << ans << endl;
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
