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

    int n;
    cin >> n;
    int d[n], f[n];
    for (int i = 0; i < n; i++)
        cin >> f[i] >> d[i];

    sort(f, f + n);
    reverse(f, f + n);
    
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += d[i - 1];
        ans -= f[i - 1] * i;
    }

    cout << ans << endl;

    return 0;
}
