// ﷽
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

    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    multiset<int> ms;

    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        ms.insert(a[i]);
        debug(i, ms);
        if (i >= k - 1) {
            ans = min(ans, *prev(ms.end()));
            ms.erase(ms.find(a[i - k + 1]));
        }
    }

    cout << ans;

    return 0;
}
