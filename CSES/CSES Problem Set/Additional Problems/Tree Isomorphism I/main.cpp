// ﷽
// https://cses.fi/problemset/task/1700

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

map<vector<int>, int> values;

int dfs(int u, int p, vvi &adj) {
    vector<int> cur;
    for (int v: adj[u]) {
        if (v == p) continue;
        cur.push_back(dfs(v, u, adj));
    }

    sort(all(cur));

    if (values.count(cur)) {
        return values[cur];
    } else {
        values[cur] = sz(values) + 1;
        return values[cur];
    }
}


void solve() {
    int n;
    cin >> n;

    values.clear();

    vvi adj1(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }

    vvi adj2(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }

    auto x = dfs(1, 0, adj1);
    auto y = dfs(1, 0, adj2);

    if (x == y) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
