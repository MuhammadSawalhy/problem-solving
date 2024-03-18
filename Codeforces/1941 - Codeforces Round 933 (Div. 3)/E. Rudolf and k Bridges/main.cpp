// ﷽
// https://codeforces.com/contest/1941/problem/E

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

void solve() {
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    int cell[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cell[i][j];
        }
    }


    vector<int> cost(n);

    for (int i = 0; i < n; i++) {
        vector<int> dp(m);
        dp[0] = cell[i][0] + 1;

        multiset<int> ms;
        ms.insert(dp[0]);

        for (int j = 1; j < m; j++) {
            // erase k where (j - k - 1 > d)
            // erase k where (k < j - d - 1)
            int k = j - d - 2;
            if (k >= 0) ms.erase(ms.find(dp[k]));

            int mn = *ms.begin();
            dp[j] = mn + cell[i][j] + 1;
            ms.insert(dp[j]);
        }

        cost[i] = dp[m - 1];
    }

    for (int i = 1; i < n; i++) {
        cost[i] += cost[i - 1];
    }

    int mn = cost[k - 1];
    for (int i = k; i < n; i++) {
        mn = min(mn, cost[i] - cost[i - k]);
    }
    cout << mn << endl;
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
