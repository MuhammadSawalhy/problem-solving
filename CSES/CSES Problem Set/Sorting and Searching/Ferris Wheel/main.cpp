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

    int n, x;
    cin >> n >> x;

    int p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];

    sort(p, p + n);

    int ans = 0;
    for (int i = 0, j = n - 1; i <= j; j--) {
        if (p[i] + p[j] <= x) i++;
        ans++;
    }

    cout << ans << endl;

    return 0;
}
