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

    array<int, 2> a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i][1] >> a[i][0];
    }

    sort(a, a + n);
    int ans = 0, r = 0;

    for (int i = 0; i < n; i++) {
        if (a[i][1] >= r) {
            ans++;
            r = a[i][0];
        }
    }

    cout << ans << endl;

    return 0;
}
