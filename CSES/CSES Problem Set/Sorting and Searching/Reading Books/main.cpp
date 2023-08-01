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

    int n; cin >> n; ll t[n];
    for (int i = 0; i < n; i++) cin >> t[i];

    int mx = *max_element(t, t + n);
    long long sum = accumulate(t, t + n, 0LL);
    if (mx > sum - mx) {
        cout << 2 * mx << endl;
    } else {
        cout << sum << endl;
    }

    return 0;
}
