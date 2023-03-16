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

/*

1 5
2 5
2 7
3 3
4 10

*/

void solve() {
    int n;
    cin >> n;
    pair<int, int> a[n];
    multiset<int> ms;
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second, ms.insert(a[i].second);

    sort(a, a + n, greater<pair<int, int>>());
    int ans = 1e9;
    int mxb = -1e9;
    for (auto [x, y]: a) {
        ms.erase(ms.find(y));
        auto it = ms.lower_bound(x);
        if (it != ms.end())
            ans = min(ans, abs(max(*it, mxb) - x));
        if (it != ms.begin())
            ans = min(ans, abs(max(*prev(it), mxb) - x));
        ans = min(ans, abs(mxb - x));
        mxb = max(mxb, y);
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
