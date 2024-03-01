// ﷽
// https://codeforces.com/contest/1816/problem/E

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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n], revadj[n];
    vector<int> outdeg(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        revadj[v].push_back(u);
        outdeg[u]++;
    }

    vector<bool> vis(n);
    vis[0] = true;
    vector<int> qu{0};
    for (int i = 0; i < (int) qu.size(); i++) {
        int u = qu[i];
        for (int v: revadj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                qu.push_back(v);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cout << "INFINITE\n";
            return;
        }
    }

    deque<deque<int>> dq;
    vector<int> fr(n, 1e9);
    vis = vector<bool>(n);
    vis[0] = true;
    qu = {0};

    for (int i = 0; i < (int) qu.size(); i++) {
        int u = qu[i];
        for (int v: adj[u]) minit(fr[u], fr[v]);
        if (fr[u] == 1e9) fr[u] = 0;
        fr[u]++;
        dq.push_back({});
        debug(u, fr[u]);
        assert(dq.size() >= fr[u]);
        for (int i = 0; i < fr[u]; i++) {
            dq[i].push_front(u);
        }
        if (dq.back().size() == 0) dq.pop_back();
        for (int v: revadj[u]) {
            if (!vis[v]) {
                qu.push_back(v);
                vis[v] = true;
            }
        }
    }

    int sz = 0;
    for (auto &d: dq) sz += d.size(), debug(d);
    cout << "FINITE\n";
    cout << sz << '\n';
    for (auto &d: dq) {
        for (int x: d) cout << x + 1 << ' ';
    }
    cout << '\n';
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
