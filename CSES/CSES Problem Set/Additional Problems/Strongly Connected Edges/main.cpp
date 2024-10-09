// ﷽
// https://cses.fi/problemset/task/2177

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

const int N = 1e5 + 5;
vvi adj;
vector<pii> ans;
map<pii, bool> vis;
bool vis2[N];

void dfs(int i) {
    if (vis2[i]) return;
    vis2[i] = true;
    for (auto j: adj[i]) {
        if (vis[{i, j}] || vis[{j, i}]) continue;
        vis[{i, j}] = true;
        dfs(j);
        ans.push_back({i, j});
    }
}

struct SCC {
    int N, ID = 0, COMP = 0;
    vector<vector<int>> adj;
    vector<int> id, comp, st;

    SCC(const vector<vector<int>> &adj) : adj(adj), N(adj.size()) {
        id.resize(N), comp = vector<int>(N, -1);
        go();
    }

    void go() {
        for (int i = 0; i < N; i++)
            if (!id[i]) dfs(i);
    }

    int dfs(int i) {
        int low = id[i] = ++ID;
        st.push_back(i);
        for (int j: adj[i])
            if (comp[j] == -1)
                // id[j] != 0 -> in stack, don't dfs
                low = min(low, id[j] ?: dfs(j));
        if (low == id[i]) {
            COMP++;
            for (int j = -1; j != i;)
                comp[j = st.back()] = COMP, st.pop_back();
        }
        return low;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    adj = vvi(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) dfs(i);

    vvi diradj(n);

    for (auto [u, v]: ans) {
        diradj[u].push_back(v);
    }

    debug(diradj);
    SCC scc(diradj);

    if (scc.COMP != 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for (auto [u, v]: ans) {
        cout << u + 1 << ' ' << v + 1 << endl;
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
