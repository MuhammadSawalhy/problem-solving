#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int comp[N], cnt[N], vis[N], c = 0;
vector<int> f[N], g[N], ff[N];

void getcomp(int i) {
    comp[i] = c;
    for (auto j: g[i]) {
        if (comp[j] == 0) getcomp(j);
    }
}

void visit(int i) {
    vis[i] = true;
    for (auto j: ff[i]) {
        if (vis[j] == false) visit(j);
    }
}

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        f[u].push_back(v);
        f[v].push_back(u);
        edges.push_back({u, v});
    }
    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (comp[i] == 0) ++c, getcomp(i);
    }

    int ans = 0;

    for (auto [i, j]: edges) {
        if (comp[i] != comp[j]) ans++;
        else {
            ff[i].push_back(j);
            ff[j].push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        cnt[comp[i]]++;
        visit(i);
    }

    for (int i = 1; i <= c; i++) ans += cnt[i] - 1;

    cout << ans << endl;
    for (int i = 0; i <= n; i++) ff[i].clear(), f[i].clear(), g[i].clear(), comp[i] = 0, c = 0, vis[i] = 0, cnt[i] = 0;
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
