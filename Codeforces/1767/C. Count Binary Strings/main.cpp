// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

const int N = 101, mod = 998244353;
int cons[N][N], n;
int dp[N][N][N];

int solve(int i, int j, int k) {
    if (i > n) return 1;
    int &r = dp[i][j][k];
    if (~r) return r;
    r = 0;

    bool valid_1 = true, valid_0 = true;

    for (int r = 0; r <= i; r++) {
        valid_0 &= cons[r][i] == 0 || cons[r][i] == 1 && k < r || cons[r][i] == 2 && k >= r;
        valid_1 &= cons[r][i] == 0 || cons[r][i] == 1 && j < r || cons[r][i] == 2 && j >= r;
    }

    if (valid_0) r = (r + solve(i + 1, i, k)) % mod;
    if (valid_1) r = (r + solve(i + 1, j, i)) % mod;
    return r;
}

void solve() {

    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            cin >> cons[i][j];

    memset(dp, -1, sizeof dp);

    cout << solve(1, 0, 0) << endl;
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
