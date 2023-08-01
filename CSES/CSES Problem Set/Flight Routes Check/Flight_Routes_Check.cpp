// ﷽
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

    vector<vector<int>> adj(n);

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
    }

    SCC scc(adj);

    int a = scc.comp[0], b = a;
    for (int i = 0; i < n; i++) {
        b = scc.comp[i];
        if (b != a) break;
    }

    if (a == b) {
        cout << "YES\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (auto j : adj[i]) {
            if (scc.comp[i] == a && scc.comp[j] == b) {
                swap(a, b);
                goto end;
            }
        }
    }
    end:

    int A, B;
    for (int i = 0; i < n; i++) {
        if (scc.comp[i] == a) A = i;
        if (scc.comp[i] == b) B = i;
    }

    cout << "NO\n";
    cout << A + 1 << ' ' << B + 1 << '\n';

    return 0;
}
