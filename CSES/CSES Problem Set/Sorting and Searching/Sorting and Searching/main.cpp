// ﷽
// 11 جُمادى الآخرة 1444
// Jan 03, 2023
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

    int n, m, k;
    cin >> n >> m >> k;

    int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);

    int ans = 0;
    for (int i = 0, j = 0; j < m && i < n; i++) {
        while (j < m && b[j] + k < a[i]) j++;
        if (j < m && b[j] - k <= a[i]) j++, ans++;
    }

    cout << ans;

    return 0;
}
