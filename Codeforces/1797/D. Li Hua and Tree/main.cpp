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

const int N = 2e5;
int n, m, a[N], fa[N];
set<int> adj[N];
ll imp[N], vertcnt[N];
bool isleaf[N];
set<pair<int, int>> sons[N];

void dfs(int i, int p) {
    bool leaf = true;
    vertcnt[i] = 1;
    imp[i] = a[i];
    fa[i] = p;
    for (auto j: adj[i]) {
        if (j == p) continue;
        leaf = false;
        dfs(j, i);
        vertcnt[i] += vertcnt[j];
        imp[i] += imp[j];
        sons[i].insert({vertcnt[j], -j});
    }
    isleaf[i] = leaf;
}

void rotate(int x) {
    auto [vcnt, i] = *prev(sons[x].end());
    i = -i;
    ll im = imp[i];
    debug(i, x);
    debug(vertcnt[x], imp[x], vertcnt[i], imp[i]);

    // add x to i
    vertcnt[i] = vertcnt[x];
    imp[i] = imp[x];

    // remove i from x
    vertcnt[x] -= vcnt;
    imp[x] -= im;

    // add edge between i and fa[x]
    adj[fa[x]].insert(i);
    adj[i].insert(fa[x]);
    // remove edge between x and fa[x]
    adj[fa[x]].erase(x);
    adj[x].erase(fa[x]);

    // update heavy son
    sons[fa[x]].erase({vertcnt[i], -x});
    sons[fa[x]].insert({vertcnt[i], -i});
    sons[i].insert({vertcnt[x], -x});
    sons[x].erase(prev(sons[x].end()));

    // update parents
    fa[i] = fa[x];
    fa[x] = i;

    debug(vertcnt[x], imp[x], vertcnt[i], imp[i]);
    isleaf[i] = false;
    isleaf[x] = vertcnt[x] == 1;
    if (isleaf[x])
        assert(adj[x].size() == 1);
    else
        assert(sons[x].size() > 0);
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        adj[i].clear();
        sons[i].clear();
        imp[i] = vertcnt[i] = 0;
        cin >> a[i];
    }

    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    dfs(0, 0);

    int t, x;
    while (m--) {
        cin >> t >> x, x--;
        if (t == 1) {
            cout << imp[x] << '\n';
        } else {
            if (isleaf[x]) continue;
            rotate(x);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
