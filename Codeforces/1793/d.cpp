// ﷽
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    int p[n], q[n];
    int ip[n + 1], iq[n + 1];

    for (int i = 0; i < n; i++)
        cin >> p[i], ip[p[i]] = i;
    for (int i = 0; i < n; i++)
        cin >> q[i], iq[q[i]] = i;

    int mn = min(ip[1], iq[1]), mx = max(ip[1], iq[1]);
    ll x = mn, y = n - mx - 1, z = max(0LL, n - x - y - 2);
    ll ans = 1LL + (x) * (x + 1) / 2 + (y) * (y + 1) / 2 + (z) * (z + 1) / 2;

    for (int i = 2; i <= n; i++) {
        // choose right or left part where [1...i] exists
        int j = min(ip[i], iq[i]), k = max(ip[i], iq[i]);
        if (mn > k && mx > k) {
            ll x = mn - k, y = n - mx;
            debug(i, j, k, x, y);
            ans += x * y;
        }
        if (mn < j && mx < j) {
            ll x = mn + 1, y = j - mx;
            debug(i, j, k, x, y);
            ans += x * y;
        }
        if (mn > j && mx < k) {
            ll x = mn - j, y = k - mx;
            debug(i, j, k, x, y);
            ans += x * y;
        }
        mn = min(mn, j);
        mx = max(mx, k);
    }

    cout << ans << endl;

    return 0;
}
