// ﷽
// https://codeforces.com/contest/1900/problem/E

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
    vector<vector<int>> adj(n);
    vector<int> fr(n + 1), sum(n + 1);
    int val[n];
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
    }

    set<int> newadj[n + 1], revadj[n + 1];
    SCC scc(adj);
    debug(scc.comp);

    for (int i = 0; i < n; i++) {
        fr[scc.comp[i]]++;
        sum[scc.comp[i]] += val[i];
        for (auto j: adj[i]) {
            if (scc.comp[j] == scc.comp[i]) continue;
            newadj[scc.comp[i]].insert(scc.comp[j]);
            revadj[scc.comp[j]].insert(scc.comp[i]);
        }
    }

    pair<int, int> dp[n + 1];
    queue<int> q;
    vector<int> out(n + 1);

    for (int i = 0; i <= n; i++) {
        out[i] = newadj[i].size();
        debug(i, newadj[i]);
    }

    for (int i = 0; i <= n; i++) {
        if (out[i] == 0)
            q.push(i);
    }

    debug(q);

    pair<int, int> ans = {0, 0};

    auto update = [](pair<int, int> &ans, pair<int, int> a) {
        if (a.first > ans.first || a.first == ans.first && a.second < ans.second) {
            ans = a;
        }
    };

    while (q.size()) {
        int i = q.front();
        q.pop();
        update(dp[i], {fr[i], sum[i]});
        debug(i, dp[i]);
        update(ans, dp[i]);
        for (auto j: revadj[i]) {
            update(dp[j], {dp[i].first + fr[j], dp[i].second + sum[j]});
            out[j]--;
            if (out[j] == 0)
                q.push(j);
        }
    }

    cout << ans.first << ' ' << ans.second << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
