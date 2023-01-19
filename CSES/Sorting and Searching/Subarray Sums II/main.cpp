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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, x;
    cin >> n >> x;
    ll a[n], ps[n + 1], ans = 0;

    ps[0] = 0;
    for (int i = 0; i < n; i++) cin >> a[i], ps[i + 1] = a[i] + ps[i];

    map<long long, int> fr;
    for (int i = 0; i <= n; i++) {
        ans += fr[ps[i] - x];
        fr[ps[i]]++;
    }

    cout << ans << endl;

    return 0;
}
