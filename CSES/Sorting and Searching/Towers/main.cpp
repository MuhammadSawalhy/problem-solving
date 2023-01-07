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

    int n; cin >> n;
    multiset<int> ms;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        // min size on which the box can set
        auto it = ms.lower_bound(k + 1);
        if (ms.empty() || it == ms.end()) {
            ans++;
            ms.insert(k);
        } else {
            ms.erase(it);
            ms.insert(k);
        }
    }

    cout << ans << endl;

    return 0;
}
