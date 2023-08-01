// ﷽
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

const int N = 1001, X = 1e5 + 1;
int n, x, h[N], s[N];
int dp[X];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 0; i < n; i++)
        for (int j = x; j >= h[i]; j--) 
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);

    cout << dp[x] << endl;
    return 0;
}
