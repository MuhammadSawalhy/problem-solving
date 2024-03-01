#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
        c[i]--;
    }

    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<std::map<int, int>> mp(n);
    i64 ans = 0;
    auto dfs = [&](auto self, int x, int p) -> void {
        for (auto y: adj[x]) {
            if (y == p) {
                continue;
            }
            self(self, y, x);
            if (mp[y].count(c[x])) {
                ans += mp[y][c[x]];
                mp[y].erase(c[x]);
            }
            if (mp[x].size() < mp[y].size()) {
                std::swap(mp[x], mp[y]);
            }
            for (auto [a, b]: mp[y]) {
                ans += 1LL * b * mp[x][a];
                mp[x][a] += b;
            }
            mp[y].clear();
        }
        mp[x][c[x]] += 1;
    };
    dfs(dfs, 0, -1);
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
