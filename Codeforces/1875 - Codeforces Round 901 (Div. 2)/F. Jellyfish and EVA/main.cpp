// ﷽
// https://codeforces.com/contest/1875/problem/F

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
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<double> dp(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    dp[n] = 1;

    for (int i = n - 1; i >= 1; i--) {
        for (auto j: adj[i]) {
            int m = adj[i].size(), r = 0;
            double p = 1.0;
            while (r < m) {
                dp[i] = max(dp[i], dp[j] * (1.0 / (m - r)) * p);
                p *= 1.0 * ((m - r) * (m - r - 1)) / ((m - r) * (m - r));
                r += 2;
            }
        }
    }

    debug(dp);

    cout << dp[1] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cout << fixed << setprecision(10);
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
