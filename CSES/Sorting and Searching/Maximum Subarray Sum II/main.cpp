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

const int N = 2e5, LOG = 32 - __builtin_clz(N);
ll n, a, b, x[N], ps[N + 1][LOG];


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
        cin >> x[i], ps[i + 1][0] = ps[i][0] + x[i];

    // sparse table of ps

    for (int l = 1; l < LOG; l++) {
        for (int i = 0; (i + (1 << l)) <= n + 1; i++) {
            ps[i][l] = min(ps[i][l - 1], ps[i + (1 << (l - 1))][l - 1]);
        }
    }

    ll ans = -1e18;

    for (int i = 1; i <= n; i++) {
        int l = i - b;
        int r = i - a + 1;
        l = max(0LL, l);
        if (r <= l) continue;
        int log = 31 - __builtin_clz(r - l);
        ll mn = min(ps[l][log], ps[r - (1 << log)][log]);
        ans = max(ans, ps[i][0] - mn);
    }

    cout << ans;

    return 0;
}
