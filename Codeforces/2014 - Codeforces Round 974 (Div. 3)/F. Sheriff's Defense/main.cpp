// ﷽
// https://codeforces.com/contest/2014/problem/F

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 2e5 + 5;
int n, c;
vector<int> adj[N];
int dp[N][2][2];
int a[N];

void dfs(int i, int p, bool isp, bool isi) {
    if (dp[i][isp][isi] > -1e18) return;

    for (auto j: adj[i]) {
        if (j == p) continue;
        dfs(j, i, isi, 0);
        dfs(j, i, isi, 1);
    }

    if (isi) {
        int s = isp ? -2 * c + a[i] : a[i];
        for (auto j: adj[i]) {
            if (j == p) continue;
            s += max(dp[j][isi][0], dp[j][isi][1]);
        }

        dp[i][isp][isi] = s;
    } else {
        int s = 0;
        for (auto j: adj[i]) {
            if (j == p) continue;
            s += max(dp[j][isi][0], dp[j][isi][1]);
        }
        dp[i][isp][isi] = s;
    }
    debug(i, isp, isi);
    debug(dp[i][isp][isi]);
}

void solve() {
    cin >> n >> c;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = -1e18;
    }

    dfs(0, 0, 0, 0);
    dfs(0, 0, 0, 1);

    cout << max(dp[0][0][0], dp[0][0][1]) << '\n';

    for (int i = 0; i < n; i++) {
        adj[i].clear();
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
