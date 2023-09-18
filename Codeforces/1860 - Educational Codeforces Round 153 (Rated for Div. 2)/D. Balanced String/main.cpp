// ﷽
// https://codeforces.com/contest/1860/problem/D
// Codeforces -> Educational Codeforces Round 153 (Rated for Div. 2) -> D. Balanced String

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

const int N = 101, M = N * N * 2 + 1;
int dp[2][N][M];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;

    int DP = 0;
    int n = s.size();
    const int M = n * n * 2 + 1;
    const int inf = 1e9;

    for (int j = 0; j <= N; j++) {
        for (int k = 0; k <= M; k++) {
            dp[DP][j][k] = inf;
        }
    }

    dp[DP][0][n * n] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= M; k++) {
                dp[DP ^ 1][j][k] = inf;
            }
        }

        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= M; k++) {
                // put 0
                if (k + i - j <= M && k + i - j >= 0)
                    minit(dp[DP ^ 1][j + 1][k + i - j], dp[DP][j][k] + (s[i] == '1'));
                // put 1
                if (k - j <= M && k - j >= 0)
                    minit(dp[DP ^ 1][j + 0][k - j], dp[DP][j][k] + (s[i] == '0'));
            }
        }

        DP ^= 1;
    }

    cout << dp[DP][count(all(s), '0')][n * n] / 2 << '\n';

    return 0;
}
