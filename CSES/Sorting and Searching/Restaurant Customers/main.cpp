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

    int n;
    cin >> n;

    vector<pair<int, int>> a(n << 1);
    for (int i = 0; i < n << 1; i += 2) {
        cin >> a[i].first >> a[i + 1].first;
        a[i].second = 1;
        a[i + 1].second = -1;
        a[i + 1].first++; // arrival happens before leaving
    }

    sort(all(a));
    debug(a);

    int ans = 0, cnt = 0;
    for (int i = 0; i < n << 1; i++) {
        cnt += a[i].second;
        ans = max(cnt, ans);
    }

    cout << ans << endl;

    return 0;
}
