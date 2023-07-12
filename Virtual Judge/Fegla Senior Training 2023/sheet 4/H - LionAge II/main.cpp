// ﷽
#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

const int N = 101;
string s;
int k, n;
int dp[N][N][29];
map<pair<int, int>, int> value;

int solve(int i, int j, int c) {
    if (j > k) return -1e9;
    if (i >= s.size()) return 0; 
    int &r = dp[i][j][c];
    if (~r) return r;

    r = -1e9;

    for (int ch = 0; ch < 26; ch++) {
        r = max(r, solve(i + 1, j + (s[i] - 'a' != ch), ch) + value[{ c, ch }]);
    }

    return r;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> s >> k >> n;

    char x, y;
    int c;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> c;
        value[{x - 'a', y - 'a'}] = c;
    }

    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, 27);

    return 0;
}
