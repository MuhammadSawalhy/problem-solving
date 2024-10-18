// ﷽
// https://cses.fi/problemset/task/1706

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

const int N = 1e5 + 1;
vector<int> adj[N];
bitset<N> b, vis;

int dfs(int i) {
    vis[i] = true;
    int cnt = 1;
    for (auto x: adj[i]) {
        if (vis[x]) continue;
        cnt += dfs(x);
    }
    return cnt;
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    b[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int cnt = dfs(i);
        debug(cnt);
        b |= b << cnt;
    }
    auto ans = b.to_string().substr(N - n - 1, n);
    reverse(all(ans));
    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
