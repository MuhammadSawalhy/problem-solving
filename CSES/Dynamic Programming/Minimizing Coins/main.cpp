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

    int n, x; cin >> n >> x; ll c[n];
    for (int i = 0; i < n; i++) cin >> c[i];
    
    int inf = 1e9;
    int N = x + (int)1e6 + 1;
    int dp[N];
    dp[0] = 0;

    for (int i = 1; i < N; i++) dp[i] = inf;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < n; j++) {
            dp[i + c[j]] = min(dp[i + c[j]], dp[i] + 1);
        }
    }

    if (dp[x] == inf) {
        cout << -1 << endl;
    } else {
        cout << dp[x] << endl;
    }

    return 0;
}
