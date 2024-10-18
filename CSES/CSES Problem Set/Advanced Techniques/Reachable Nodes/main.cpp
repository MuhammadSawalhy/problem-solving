// ﷽
// https://cses.fi/problemset/task/2143

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
#define vvi vector<vector<int>>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 5e4 + 4;
bitset<N> reach[N];
vvi adj;
int n, m, q;

bool vis[N];

void dfs(int i, const vvi &adj) {
    if (vis[i]) return;
    vis[i] = true;
    reach[i][i] = true;
    for (auto j: adj[i]) {
        dfs(j, adj);
        reach[i] |= reach[j];
    }
}

void solve() {
    cin >> n >> m;

    adj = vvi(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    for (int i = 0; i < n; i++) {
        dfs(i, adj);
    }

    for (int i = 0; i < n;i++) {
        cout << reach[i].count() << ' ';
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 1;
    // cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}

