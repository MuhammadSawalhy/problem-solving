// ﷽
// https://codeforces.com/contest/2040/problem/E

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
#define vii vector<pii>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})


void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> adj[n];
    vector<int> deg(n), par(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    function<void(int, int)> dfs = [&](int i, int p) {
        par[i] = p;
        for (auto j: adj[i]) {
            if (j != p) dfs(j, i);
        }
    };

    dfs(0, -1);

    while (q--) {
        int x, v;
        cin >> x >> v;
        debug(x, v);
        x--;

        if (x == 0) {
            cout << 0 << endl;
            continue;
        }

        x = par[x];

        if (x == 0) {
            cout << 1 << endl;
            continue;
        }

        int ans = 0;

        vector<int> vals;

        while (x != 0) {
            if (par[x] == 0) {
                ans += deg[x] * 2 - 1;
                vals.push_back(1 - (deg[x] * 2 - 1));
                break;
            } else {
                ans += deg[x] * 2;
                vals.push_back(2 - (deg[x] * 2));
                x = par[par[x]];
            }
        }

        sort(all(vals));
        debug(vals);
        for (int i = 0; i < min(v, sz(vals)); i++) {
            ans += vals[i];
        }

        cout << ans + 1 << endl;
    }
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
