// ﷽
// https://codeforces.com/contest/2044/problem/G1

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
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i], a[i]--;

    vvi adj(n);
    vi indeg(n);
    for (int i = 0; i < n; i++) {
        adj[i].push_back(a[i]);
        indeg[a[i]]++;
    }

    SCC scc(adj);
    vector<bool> isc(n, false);

    vi fr(n);
    for (int i = 0; i < n; i++) {
        fr[scc.comp[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (fr[scc.comp[i]] > 1) isc[i] = true;
    }

    int ans = 2;
    vi cnt(n, 1);

    queue<int> qu;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            qu.push(i);
        }
    }

    while (qu.size()) {
        int i = qu.front();
        qu.pop();
        for (auto j: adj[i]) {
            if (isc[j]) cnt[j] = max(cnt[j], cnt[i] + 1);
            else cnt[j] += cnt[i];
            indeg[j]--;
            if (indeg[j] == 0) {
                qu.push(j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (isc[i]) {
            ans = max(ans, cnt[i] + 1);
        }
    }

    cout << ans << endl;
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

