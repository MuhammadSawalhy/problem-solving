// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

const int N = 1e5;
vector<pair<int, int>> adj[N];
int value[N];

void dfs(int i, int p, int x = 0) {
    value[i] = x;
    for (auto [child, w]: adj[i]) {
        if (child == p) continue;
        dfs(child, i, x ^ w);
    }
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        value[i] = 0;
        adj[i].clear();
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs(0, 0);

    vector<pair<int, int>> xors(1 << 20, {-1, -1});

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto [a, b] = xors[value[i] ^ value[j]];
            if (a != -1) {
                if (a > b) swap(a, b);
                cout << a + 1 << " " << b + 1 << " " << i + 1 << " " << j + 1 << "\n";
                return;
            }
            xors[value[i] ^ value[j]] = {i, j};
        }
    }

    cout << -1 << '\n';
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
