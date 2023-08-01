// ﷽
#include <bits/stdc++.h>

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

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll n;
    int k;
    cin >> n >> k;

    ll p[k];

    for (int i = 0; i < k; i++)
        cin >> p[i];

    ll ans = 0;
    for (int mask = 1; mask < 1 << k; mask++) {
        ll a = 1;
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            if ((~mask >> i) & 1) continue;
            cnt++;
            if (n / a < p[i]) {
                a = n + 1;
                break;
            }
            a *= p[i];
        }
        ans += (cnt & 1 ? 1 : -1) * n / a;
    }

    cout << ans << endl;

    return 0;
}
