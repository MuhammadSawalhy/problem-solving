// ﷽
// https://codeforces.com/contest/1327/problem/F

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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

constexpr int MOD = 998244353;

int n, k, m;
const int N = 5e5 + 5;
vector<array<int, 4>> rngs, edges;
int dp[N];

int solve_bit(int b) {
    int ones = 0, all = 0;
    int latest = 0;

    for (int i = 0; i <= n; i++) dp[i] = 0;
    dp[0] = 1;
    debug(b);

    int j = 0;
    for (int i = 1; i <= n; i++) {
        while (j < edges.size() && edges[j][0] < i) j++;
        while (j < edges.size() && edges[j][0] == i) {
            all += edges[j][1];
            ones += edges[j][1] * (edges[j][2] >> b & 1);

            if (edges[j][1] == -1 && edges[j][2] >> b & 1 ^ 1) {
                maxit(latest, edges[j][3]);
            }
            j++;
        }

        if (!ones) {
            // can put zero here
            dp[i] = dp[i - 1] - (latest > 0 ? dp[latest - 1] : 0);
        }

        dp[i] = (dp[i] + dp[i - 1]) % MOD;
    }

    while (j < edges.size() && edges[j][0] == n + 1) {
        if (edges[j][1] == -1 && edges[j][2] >> b & 1 ^ 1) {
            maxit(latest, edges[j][3]);
        }
        j++;
    }

    dp[n] = dp[n] - (latest > 0 ? dp[latest - 1] : 0);
    return dp[n];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> k >> m;

    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        rngs.push_back({l, r, x});
        edges.push_back({l, 1, x, r});
        edges.push_back({r + 1, -1, x, l});
    }

    sort(all(edges));

    int ans = 1;
    for (int b = 0; b < k; b++) {
        ans = 1LL * ans * solve_bit(b) % MOD;
    }

    ans = (ans + MOD) % MOD;
    cout << ans << '\n';

    return 0;
}
