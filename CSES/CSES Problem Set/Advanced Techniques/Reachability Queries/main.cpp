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

bool vis[N];

void dfs(int i, const vvi &adj) {
    if (vis[i]) return;
    vis[i] = true;
    reach[i][i] = true;
    for (auto j : adj[i]) {
        dfs(j, adj);
        reach[i] |= reach[j];
    }
}

void solve() {
    cin >> n >> m >> q;

    adj = vvi(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    SCC scc(adj);

    vvi compressed(n + 1);

    for (int i = 0; i < n; i++) {
        for (auto j: adj[i]) {
            if (scc.comp[i] != scc.comp[j]) {
                compressed[scc.comp[i]].push_back(scc.comp[j]);
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        dfs(i, compressed);
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        if (reach[scc.comp[u]][scc.comp[v]]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
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
