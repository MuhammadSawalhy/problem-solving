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
#define int    long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        ans = max(ans, 1LL * (upper_bound(a, a + n, r) - lower_bound(a, a + n, l)));
    }

    cout << ans << endl;

    return 0;
}
