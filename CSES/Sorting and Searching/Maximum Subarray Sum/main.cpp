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
    ll ans = -1e9, cur = -1e9;
    for (int i = 0; i < n; i++) {
        int a; 
        cin >> a;
        cur = max(a, cur + a);
        ans = max(ans, cur);
    }

    cout << ans << endl;

    return 0;
}
