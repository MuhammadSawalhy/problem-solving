// ﷽
// https://cses.fi/problemset/task/1684
// CSES -> CSES Problem Set -> Giant Pizza

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

    vector<vector<int>> adj(m * 2 + 1);

    for (int i = 0; i < n; i++) {
        char t1, t2;
        int x, y;
        cin >> t1 >> x >> t2 >> y;
        if (t1 == '-') x *= -1;
        if (t2 == '-') y *= -1;
        adj[m - x].push_back(m + y);
        adj[m - y].push_back(m + x);
    }

    SCC scc(adj);

    vector<char> ans(m + 1);
    for (int i = 1; i <= m; i++) {
        if (scc.comp[m + i] == scc.comp[m - i]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        ans[i] = scc.comp[m + i] < scc.comp[m - i] ? '+' : '-';
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << ' ';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();
    return 0;
}
