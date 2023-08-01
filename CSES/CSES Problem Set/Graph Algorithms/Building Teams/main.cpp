// ﷽
#include <bits/stdc++.h>

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

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> ans(n);

    bool ok = true;
    function<void(int, int)> dfs = [&](int i, int value) {
        if (!ok || ans[i] && ans[i] == value) return;
        if (ans[i] && ans[i] != value) {
            ok = false;
            return;
        }
        ans[i] = value;
        for (int j: adj[i]) dfs(j, value ^ 3);
    };

    for (int i = 0; i < n; i++)
        if (!ans[i]) dfs(i, 1);

    if (!ok)
        cout << "IMPOSSIBLE" << endl;
    else
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }

    return 0;
}
