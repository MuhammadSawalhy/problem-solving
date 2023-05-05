// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

void solve() {
    int n;
    cin >> n;
    ll a[n];
    bool zero = false;
    for (int i = 0; i < n; i++) cin >> a[i], zero |= a[i] == 0;

    ll ans = -1e18;
    ll mn = 1e9, mx = -1e9;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            ans = max(ans, a[i] * mn);
            ans = max(ans, a[i] * mx);
        }

        mx = max(a[i], mx);
        mn = min(a[i], mn);
    }

    if (zero)
        ans = max(ans, 0ll);

    cout << ans << '\n';
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
