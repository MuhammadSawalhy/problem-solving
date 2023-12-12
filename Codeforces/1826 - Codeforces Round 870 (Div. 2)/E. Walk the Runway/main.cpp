// ﷽
// https://codeforces.com/contest/1826/problem/E

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

const int M = 505, N = 5005;
int r[M][N];

void solve() {
    int m, n;
    cin >> m >> n;

    int dp[n], p[n];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> r[i][j];
        }
    }

    vector<int> order(n);
    iota(all(order), 0);
    sort(all(order), [&](int a, int b) {
        return r[0][a] < r[0][b];
    });

    bitset<5000> ok[n];
    for (int i = 0; i < n; i++) ok[i].set();
    for (int i = 0; i < m; i++) {
        bitset<5000> cur;
        vector<int> ind[n + 1];
        for (int j = 0; j < n; j++) ind[r[i][j]].push_back(j);
        for (int j = 1; j <= n; j++) {
            for (auto k: ind[j]) ok[k] &= cur;
            for (auto k: ind[j]) cur[k] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        dp[i] = p[order[i]];
        for (int k = 0; k < i; k++) {
            if (ok[order[i]][order[k]])
                maxit(dp[i], p[order[i]] + dp[k]);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        maxit(ans, dp[i]);
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
