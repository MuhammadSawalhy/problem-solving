// ﷽
// https://codeforces.com/contest/1862/problem/F
// Codeforces -> Codeforces Round 894 (Div. 3) -> F. Magic Will Save the World

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

void solve() {
    int f, w;
    cin >> f >> w;

    int n;
    cin >> n;
    bool dp[1000'001];
    memset(dp, 0, sizeof dp);

    dp[0] = 1;
    int s = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s += x;
        for (int j = 1e6; j >= 0; j--) {
            if (j + x <= 1e6)
                dp[j + x] |= dp[j];
        }
    }

    int ans = 1e9;
    for (int j = 0; j <= 1e6; j++) {
        if (!dp[j]) continue;
        ans = min(ans, max((j + f - 1) / f, (s - j + w - 1) / w));
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
