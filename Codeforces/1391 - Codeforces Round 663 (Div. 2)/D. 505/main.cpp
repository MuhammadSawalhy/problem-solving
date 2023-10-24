// ﷽
// https://codeforces.com/contest/1391/problem/D

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

int n, m;

int diff(int a, int b) {
    return __popcount(a ^ b);
}

bool good(int a, int b, int m) {
    if (m == 2) return (diff(a, 0) + diff(b, 0)) & 1;
    return good(a & 0b11, b & 0b11, 2) && good(a >> 1, b >> 1, 2);
}

void solve(int *a[]) {
    assert(n >= m);
    if (m == 1) {
        cout << 0 << endl;
        return;
    }

    vector dp(n + 1, vector<int>(1 << m, 1e9));

    int val = 0;
    for (int j = 0; j < m; j++)
        val |= a[0][j] << j, debug(j, a[0][j]);
    debug(val);
    for (int i = 0; i < 1 << m; i++) {
        dp[1][i] = diff(val, i);
        debug(i, dp[1][i]);
    }

    for (int i = 1; i < n; i++) {
        int val = 0;
        for (int j = 0; j < m; j++)
            val |= a[i][j] << j;
        for (int j = 0; j < 1 << m; j++) {
            for (int k = 0; k < 1 << m; k++) {
                if (!good(j, k, m)) continue;
                minit(dp[i + 1][k], dp[i][j] + diff(val, k));
            }
        }
    }

    int ans = 1e9;
    for (int i = 0; i < 1 << m; i++) {
        minit(ans, dp[n][i]);
    }

    cout << ans << endl;
}

void solve() {
    cin >> n >> m;

    if (n > 3 && m > 3) {
        cout << -1 << endl;
        return;
    }

    int **a = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        a[i] = (int *) malloc(m * sizeof(int));
    }

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
        }
    }

    if (n < m) {
        int **b = (int **) malloc(m * sizeof(int *));
        for (int i = 0; i < m; i++) {
            b[i] = (int *) malloc(n * sizeof(int));
        }
        // rotate
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[j][i] = a[i][j];
            }
        }

        swap(n, m);
        solve(b);
    } else {
        solve(a);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
