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

    int t; cin >> t;
    while (t--) {
        int n, d; cin >> n >> d; ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a, a + n);

        if (a[n - 1] <= d || a[0] + a[1] <= d) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
