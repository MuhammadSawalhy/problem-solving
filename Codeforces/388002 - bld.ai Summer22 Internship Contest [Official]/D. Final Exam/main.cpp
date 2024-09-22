// ﷽
// https://codeforces.com/group/tKWnzvWA4V/contest/388002/problem/D

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
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

struct SCC {
    int N, ID = 0, COMP = 0;
    const vvi &adj;
    vector<int> id, comp, st;

    SCC(const vvi &adj) : adj(adj), N(adj.size()) {
        id = comp = vector<int>(N, -1);
        go();
    }

    void go() {
        for (int i = 0; i < N; i++)
            if (id[i] == -1) dfs(i);
    }

    int dfs(int i) {
        int low = id[i] = ID++;
        st.push_back(i);
        for (int j: adj[i])
            if (comp[j] == -1)
                low = min(low, id[j] == -1 ? dfs(j) : id[j]);
        if (low == id[i]) {
            for (int j = -1; j != i;)
                comp[j = st.back()] = COMP, st.pop_back();
            COMP++;
        }
        return low;
    }

    vvi dag(bool reverse = false) {
        vvi newadj(COMP);
        for (int i = 0; i < N; i++)
            for (auto j: adj[i])
                if (comp[i] != comp[j]) {
                    if (reverse) newadj[comp[j]].push_back(comp[i]);
                    else newadj[comp[i]].push_back(comp[j]);
                }
        return newadj;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    int M = 2 * m + 1;

    vvi adj(M);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[-a + m].push_back(b + m);
        adj[-b + m].push_back(a + m);
    }

    SCC scc(adj);

    // create DAG and statisfy deg0 and remove

    for (int i = 1; i <= m; i++) {
        if (scc.comp[i + m] == scc.comp[-i + m]) {
            cout << "-1\n";
            return;
        }
    }

    vvi dag = scc.dag(), rdag = scc.dag(true);
    vector<int> outdeg(M);
    vector<bool> active(M);

    for (int i = 0; i < M; i++) {
        outdeg[i] = sz(dag[i]);
    }

    vector<int> qu;
    vector<int> nodes[M];

    for (int i = 0; i < M; i++) {
        nodes[scc.comp[i]].push_back(i);
        if (outdeg[i] == 0) qu.push_back(i);
    }

    for (int i = 0; i < sz(qu); i++) {
        int j = qu[i]; // component
        bool ok = true;
        debug(j, nodes[j]);
        for (auto k: nodes[j]) {
            int other = 2 * m - k;
            if (active[scc.comp[other]]) {
                ok = false;
            }
        }
        if (!ok) continue;
        debug(j, nodes[j]);
        active[j] = true;
        for (auto k: rdag[j]) {
            outdeg[k]--;
            if (outdeg[k] == 0) {
                qu.push_back(k);
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        if (active[scc.comp[i + m]] ^ active[scc.comp[-i + m]] ^ 1) {
            cout << "-1\n";
            return;
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << active[scc.comp[i + m]] << ' ';
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
