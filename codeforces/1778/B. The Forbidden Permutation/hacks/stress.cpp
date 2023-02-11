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
    int n, m, d;
    cin >> n >> m >> d;
    ll p[n];
    ll pos[n + 1];
    ll a[m];
    for (int i = 0; i < n; i++) cin >> p[i], pos[p[i]] = i;
    for (int i = 0; i < m; i++) cin >> a[i];


    int ans = 1e9;

    for (int i = 0; i + 1 < m; i++) {
        int r = pos[a[i + 1]] - pos[a[i]];

        if (r > 0) {
            ans = min(ans, r);
        } else {
            ans = 0;
            break;
        }

        if (r <= d && d + 1 < n) {
            ans = min(ans, d - r + 1);
            debug(n, m, ans);
        } else if (r > d) {
            ans = 0;
            break;
        }
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
