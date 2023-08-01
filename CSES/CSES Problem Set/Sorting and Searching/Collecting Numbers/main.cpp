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

    int n; cin >> n; ll a[n];
    int index[n + 1];
    for (int i = 0; i < n; i++) cin >> a[i], index[a[i]] = i;
    
    // relative order
    // remember sorting stability
    
    sort(a, a + n);

    int ans = 1;

    // count number of invertions
    for (int i = 1; i < n; i++)
        ans += index[a[i]] < index[a[i - 1]];
    
    cout << ans << endl;

    return 0;
}
