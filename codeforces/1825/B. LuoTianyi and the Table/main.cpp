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

int n, m;
int calc(int a[]) {
    ll ans = -1e18;
    ans = max(ans, (a[n * m - 1] - a[0]) * (m - 1) + (a[n * m - 1] - a[1]) * (n - 1) + (a[n * m - 1] - min(a[0], a[1])) * (n - 1) * (m - 1));
    ans = max(ans, (a[n * m - 1] - a[0]) * (m - 1) + (a[n * m - 2] - a[0]) * (n - 1) + (max(a[n * m - 1], a[n * m - 2]) - a[0]) * (n - 1) * (m - 1));
    return ans;
}

void solve() {
    cin >> n >> m;
    ll a[n * m];

    for (int i = 0; i < n * m; i++) {
        cin >> a[i];
    }

    sort(a, a + n * m);

    ll ans = -1e18;
    ans = max(ans, calc(a));
    swap(a[n * m - 1], a[n * m - 2]);
    ans = max(ans, calc(a));
    swap(a[0], a[1]);
    ans = max(ans, calc(a));
    swap(a[n * m - 1], a[n * m - 2]);
    ans = max(ans, calc(a));
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
