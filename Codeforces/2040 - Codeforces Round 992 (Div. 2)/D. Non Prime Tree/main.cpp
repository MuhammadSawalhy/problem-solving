#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans(n), size(n);

    function<int(int, int)> calc_sz = [&](int i, int p) -> int {
        int sz = 1;
        for (int j: adj[i]) {
            if (j == p) continue;
            sz += calc_sz(j, i);
        }
        return size[i] = sz;
    };

    function<void(int, int, int, int)> dfs = [&](int i, int p, int l, int r) -> void {
        if (p == -1) ans[i] = l;
        else {
            if (abs(ans[p] - l) == 1 || abs(ans[p] - l) != 2 && abs(ans[p] - l) % 2 == 0) ans[i] = l;
            else ans[i] = r;
        }
        l++;
        for (int j: adj[i]) {
            if (j == p) continue;
            dfs(j, i, l, l + 2 * size[j] - 1);
            l += size[j] * 2;
        }
    };

    calc_sz(0, -1);
    dfs(0, -1, 1, 2 * n);

    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

