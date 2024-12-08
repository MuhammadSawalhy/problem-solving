// ﷽
// https://codeforces.com/contest/2050/problem/E

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vii vector<pii>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    string a, b, c;
    cin >> a >> b >> c;

    int n = a.size(), m = b.size(), k = c.size();

    int dp[n + 2][m + 2];
    memset(dp, '?', sizeof dp);
    dp[0][0] = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i - 1 >= 0)
                minit(dp[i][j], dp[i - 1][j] + (c[i + j - 1] != a[i - 1])), debug(i,j,a[i-1],dp[i-1][j], c[i+j-1]);
            if (j - 1 >= 0)
                minit(dp[i][j], dp[i][j - 1] + (c[i + j - 1] != b[j - 1]));
            debug(i,j,dp[i][j]);
        }
    }

    cout << dp[n][m] << endl;
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
