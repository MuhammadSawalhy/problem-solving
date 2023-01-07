// ﷽
// 12 جُمادى الآخرة 1444
// Jan 04, 2023
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k, ans = 0;
    cin >> n;
    map<int, int> mp;
    int l = 0;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (mp.count(k) && mp[k] >= l)
            l = mp[k] + 1;
        mp[k] = i;
        ans = max(ans, i - l + 1);
    }

    cout << ans << endl;

    return 0;
}
