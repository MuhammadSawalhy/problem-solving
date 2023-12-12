// ﷽
// https://codeforces.com/contest/1900/problem/C

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

const int N = 3e5 + 5, inf = 1e9;
vector<int> adj[N], dp(N);
int n;
string s;

int dfs(int i, int p) {
    int l = adj[i][0], r = adj[i][1];

    if (l == 0 && r == 0) dp[i] = 0;

    if (l != 0) {
        dfs(l, i);
        minit(dp[i], dp[l] + (s[i - 1] != 'L'));
    }

    if (r != 0) {
        dfs(r, i);
        minit(dp[i], dp[r] + (s[i - 1] != 'R'));
    }

    return dp[i];
}

void solve() {
    cin >> n;
    cin >> s;

    for (int i = 1; i <= n; i++) {
        dp[i] = inf;
        adj[i].clear();
    }

    debug(n, s);
    for (int i = 1, u, v; i <= n; i++) {
        cin >> u >> v;
        adj[i].push_back(u);
        adj[i].push_back(v);
    }

    cout << dfs(1, 1) << endl;
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
