// ﷽
// https://cses.fi/problemset/task/1686
// CSES -> CSES Problem Set -> Coin Collector

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b, a--, b--;
        adj[a].push_back(b);
    }

    SCC scc(adj);
    for (auto &i : scc.comp) i--;
    debug(scc.comp);

    vector<int> sccvalue(n), decen(n), outdeg(n);
    vector<vector<int>> revadj(n);

    for (int i = 0; i < n; i++) {
        sccvalue[scc.comp[i]] += a[i];
        for (auto j: adj[i]) {
            if (scc.comp[j] == scc.comp[i]) continue;
            revadj[scc.comp[j]].push_back(scc.comp[i]);
            outdeg[scc.comp[i]]++;
        }
    }
    debug(revadj);

    int ans = 0;
    vector<int> withzero;
    for (int i = 0; i < n; i++) {
        if (outdeg[i] == 0)
            withzero.push_back(i);
    }

    while (withzero.size()) {
        int i = withzero.back();
        ans = max(ans, decen[i] + sccvalue[i]);
        withzero.pop_back();
        for (int j : revadj[i]) {
            outdeg[j]--;
            decen[j] = max(decen[j], sccvalue[i] + decen[i]);
            if (outdeg[j] == 0) withzero.push_back(j);
        }
    }

    cout << ans << '\n';

    return 0;
}
