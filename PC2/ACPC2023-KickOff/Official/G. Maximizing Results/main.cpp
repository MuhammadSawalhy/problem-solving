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

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i], a[i] = abs(a[i]);
    }

    sort(all(a));
    reverse(all(a));

    ll ans = 1;
    for (int i = 0; i < m; i++) {
        ans *= abs(a[i]);
        ans %= (int)1e9 + 7;
    }

    cout << ans << endl;

    return 0;
}
