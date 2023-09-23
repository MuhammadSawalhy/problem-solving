// ﷽
// https://codeforces.com/problemset/problem/1870/E
// Codeforces -> CodeTON Round 6 (Div. 1 + Div. 2, Rated, Prizes!) -> E. Another MEX Problem

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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m[n + 1][n + 1];
    vector<int> fr(n + 1);
    for (int i = 0; i <= n; i++) {
        int x = 0;

        for (int j = i; j <= n; j++) {
            while (fr[x]) x++;
            m[i][j] = x;
            if (j < n) fr[a[j]]++;
        }

        for (int j = i; j < n; j++) fr[a[j]]--;
    }

    vector dp(n + 1, vector<bool>(n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int x = 0; x <= n; x++) {
            dp[i][x] = dp[i - 1][x];
        }
        for (int j = 0; j < i; j++) {
            if (m[j][i] == m[j + 1][i]) continue;
            if (m[j][i - 1] == m[j][i]) continue;
            for (int x = 0; x <= n; x++) {
                dp[i][x ^ m[j][i]] = dp[i][x ^ m[j][i]] | dp[j][x];
            }
        }
    }

    for (int i = n; i >= 0; i--) {
        if (dp[n][i]) {
            cout << i << endl;
            return;
        }
    }
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
