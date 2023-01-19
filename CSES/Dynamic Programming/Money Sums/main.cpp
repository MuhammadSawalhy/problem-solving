// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

const int N = 101, X = 1001;
bool dp[N][N * X];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    ll x[n + 1];
    for (int i = 1; i <= n; i++) cin >> x[i];

    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n * X; j++) {
            debug(j, x[i]);
            dp[i][j] = dp[i - 1][j];
            if (x[i] <= j)
                dp[i][j] |= dp[i - 1][j - x[i]];
        }
    }

    vector<int> ans;

    for (int i = 1; i < n * X; i++)
        if (dp[n][i]) ans.push_back(i);

    cout << ans.size() << endl;
    for (auto s: ans)
        cout << s << " ";

    return 0;
}
