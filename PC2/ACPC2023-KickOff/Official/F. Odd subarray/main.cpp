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

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int i = 0, j = 0;
    int odds = 0;

    int ans = -1;
    while (j < n) {
        odds += a[j++] & 1;
        while (odds > 1) {
            odds -= a[i++] & 1;
        }
        if (odds == 1)
            ans = max(ans, j - i);
    }

    cout << ans;

    return 0;
}
