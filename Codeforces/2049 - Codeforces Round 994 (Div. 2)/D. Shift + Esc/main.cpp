// ﷽
// https://codeforces.com/contest/2049/problem/D

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

const int N = 201, inf = 1e18;
int row[N][N][N];
int dp[N][N];
int a[N][N];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }

    for (int r = 0; r <= n; r++) {
        for (int l = 1; l <= m; l++) {
            for (int i = 0; i <= m; i++) {
                row[r][l][i] = inf;
            }
        }
    }

    for (int r = 0; r < n; r++) {
        debug(r);
        for (int l = 1; l <= m; l++) {
            debug(r, l);
            int sum = 0;
            for (int i = 0; i < l; i++) sum += a[r][i];
            row[r][l][0] = sum;
            for (int i = 1; i < m; i++) {
                sum -= a[r][i - 1];
                sum += a[r][(i + l - 1) % m];
                debug(i, sum);
                row[r][l][i] = min(row[r][l][i], sum);
            }
            for (int i = m - 1; i >= 0; i--)
                row[r][l][i] = min(row[r][l][i], row[r][l][(i + 1) % m] + k);
            for (int i = m - 1; i >= 0; i--)
                row[r][l][i] = min(row[r][l][i], row[r][l][(i + 1) % m] + k), debug(i, row[r][l][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = inf;
        }
    }

    for (int j = 0; j < m; j++) {
        dp[0][j] = row[0][j + 1][0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = j; k < m; k++) {
                dp[i][k] = min(dp[i][k], dp[i - 1][j] + row[i][k - j + 1][j]);
            }
        }
    }

    cout << dp[n - 1][m - 1] << endl;
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
