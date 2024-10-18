// ﷽
// https://cses.fi/problemset/task/2076

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

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 1e5 + 5;
vi adj[N];
vi ans;
int depth[N];

int dfs(int i, int p) {
    bool ok = true;
    int mn = depth[i];
    int cnt = 0;
    for (auto j: adj[i]) {
        if (j == p) continue;
        if (depth[j] == 0) {
            cnt++;
            depth[j] = depth[i] + 1;
            int x = dfs(j, i);
            minit(mn, x);
            if (x >= depth[i]) {
                ok = false;
            }
        } else if (depth[j] < depth[i] - 1) {
            // back link
            debug(i, j);
            minit(mn, depth[j]);
        }
    }

    if (!ok && !(i == 0 && cnt == 1)) ans.push_back(i);
    debug(i, cnt, mn);

    return mn;
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[0] = 1;
    dfs(0, 0);

    cout << sz(ans) << '\n';
    for (auto i: ans) {
        cout << i + 1 << ' ';
    }
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

