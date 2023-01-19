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

    int n, t;
    cin >> n >> t;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    auto valid = [&](ll x) {
        ll s = 0;
        for (int i = 0; i < n && s < 1e18; i++) s += x / a[i];
        return s >= t;
    };

    ll s = 0, e = 2e18;

    while (e - s > 1) {
        ll mid = (s + e) / 2;
        if (valid(mid)) e = mid;
        else
            s = mid;
    }

    cout << e << endl;

    return 0;
}
