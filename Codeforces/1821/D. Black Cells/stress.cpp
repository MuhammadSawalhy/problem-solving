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
#define all(v) v.begin(), v.end()

void solve() {
    int n, k;
    cin >> n >> k;

    int l[n], r[n], s[n];
    for (int i = 0; i < n; i++)
        cin >> l[i];
    for (int i = 0; i < n; i++)
        cin >> r[i], s[i] = r[i] - l[i] + 1;

    const ll inf = 1e12;
    ll ans = inf;
    for (int mask = 0; mask < (1 << n); mask++) {
        int last = -1;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) {
                sum += s[i];
                last = i;
            }
        }
        if (last == -1 || sum < k) continue;
        ll x = max(l[last] * 1LL, l[last] + (k - (sum - s[last])) - 1);
        ll cur = __builtin_popcountll(mask) * 2ll + x;
        if (cur < ans) {
            ans = cur;
            debug_bits(mask, 1e9, n);
        }
    }
    if (ans == inf) ans = -1;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
