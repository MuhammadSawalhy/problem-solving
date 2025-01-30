#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
int n;
vector<int> adj[N];
int mx[N];

void solve() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    multiset<int> deg;
    int ans = 0;
    for (int i = 0; i < n; i++) deg.insert(adj[i].size());

    for (int i = 0; i < n; i++) {
        deg.erase(deg.find(adj[i].size()));
        for (auto j: adj[i]) {
            ans = max(ans, (int) adj[i].size() + (int) adj[j].size() - 2);
            deg.erase(deg.find(adj[j].size()));
        }
        if (deg.size())
            ans = max(ans, (int) adj[i].size() + (*deg.rbegin()) - 1);
        for (auto j: adj[i]) deg.insert(adj[j].size());
        deg.insert(adj[i].size());
    }

    cout << ans << '\n';
    for (int i = 0; i < n; i++) adj[i].clear();
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
