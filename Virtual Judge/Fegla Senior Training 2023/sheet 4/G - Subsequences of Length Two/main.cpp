// ﷽
#include <bits/stdc++.h>

// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx,avx2,fma")

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

const int N = 202;
int n, k;
string s, t;
ll dp[N][N][N];
bool vis[N][N][N];
// dp[i][j][k].first =
//     j is the number of t[0] in before i
//     k operations already done

ll solve(int i, int j, int ops) {
    if (ops > k) return -1e18;
    if (i >= n) return 0;
    if (vis[i][j][ops])
        return dp[i][j][ops];

    vis[i][j][ops] = true;

    auto a = solve(i + 1, j + (s[i] == t[0]), ops);
    auto b = solve(i + 1, j + 1, ops + 1);
    auto c = solve(i + 1, j + (t[1] == t[0]), ops + 1);

    ll ans = -1e18;

    ans = max(ans, b);
    ans = max(ans, a + (s[i] == t[1]) * j);
    ans = max(ans, c + j);

    return dp[i][j][ops] = ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n >> k;
    cin >> s >> t;

    cout << solve(0, 0, 0);

    return 0;
}
