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

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()

struct SCC {
    int N, ID = 0, COMP = 0;
    vector<vector<int>> adj;
    vector<int> id, comp, st;

    SCC(int N) : N(N) {
        adj.resize(N), id.resize(N), comp = vector<int>(N, -1);
    }

    void add_edge(int u, int v) { adj[u].push_back(v); }

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

    void gen() {
        for (int i = 0; i < N; i++)
            if (!id[i]) dfs(i);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    SCC scc(n);
    vector<int> revadj[n];

    vector<int> ans(n);
    for (int i = 0, x; i < n; i++) {
        cin >> x, x--;
        scc.add_edge(i, x);
        revadj[x].push_back(i);
        if (i == x) ans[i] = 1;
    }

    scc.gen();

    map<int, int> fr;
    for (int i = 0; i < n; i++) {
        fr[scc.comp[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (fr[scc.comp[i]] > 1) {
            ans[i] = fr[scc.comp[i]];
        }
    }

    function<void(int)> dfs = [&](int i) {
        for (auto j: revadj[i]) {
            if (ans[j]) continue;
            ans[j] = ans[i] + 1;
            dfs(j);
        }
    };

    for (int i = 0; i < n; i++) {
        if (ans[i])
            dfs(i);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';

    return 0;
}
