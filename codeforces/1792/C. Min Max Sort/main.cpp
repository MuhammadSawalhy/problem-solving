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
    int n; cin >> n; ll a[n];
    int ind[n + 1];
    for (int i = 0; i < n; i++) cin >> a[i], ind[a[i]] = i;

    int ans = 0;

    for (int x = n / 2; x >= 1; x--) {
        int y = (n + 1) / 2 + (n / 2 - x + 1);
        if (ind[y] < ind[x] || ind[x + 1] < ind[x] || ind[y] < ind[y - 1]) {
            ans = x;
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
