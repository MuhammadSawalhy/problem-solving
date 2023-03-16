// ﷽
#include <algorithm>
#include <array>
#include <assert.h>
#include <cmath>
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

void solve() {
    int n, k, x;
    cin >> n;
    k = 0, x = 0;
    ll a[n + 1];
    ll ps[n + 1];
    ps[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], ps[i] = ps[i - 1] + a[i];

    if (x < 0) {
        k = n - k;
        x *= -1;
    }

    auto calc = [&](int l, int r) {
        if (r - l >= k)
            return (ps[r] - ps[l]) + k * x - ((r - l) - k) * x;
        else
            return (ps[r] - ps[l]) + (r - l) * x;
    };

    auto calc2 = [&](int l, int r) {
        if (n - (r - l) < k) {
            ll ans = ps[r] - ps[l];
            k -= n - (r - l);
            return ans + k * x - ((r - l) - k) * x;
        } else
            return (ps[r] - ps[l]) + (r - l) * x;
    };

    ll ans = -1e18;
    for (int i = 1, j = 0; i <= n; i++) {
        while (j + 1 < i && calc(j + 1, i) >= calc(j, i))
            j++;
        // we have best j for this i
        debug(i, j);
        ans = max(ans, calc(j, i));
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
