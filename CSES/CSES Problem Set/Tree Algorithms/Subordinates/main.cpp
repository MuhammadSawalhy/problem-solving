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

    int n;
    cin >> n;
    int ans[n];
    memset(ans, 0, sizeof ans);
    vector<int> adj[n];
    for (int i = 1; i < n; i++) {
        int p; cin >> p, p--;
        adj[p].push_back(i);
    }

    function<void(int, int)> dfs = [&](int i, int p) {
        for (auto c : adj[i]) {
            dfs(c, i);
            ans[i] += ans[c] + 1;
        }
    };

    dfs(0, 0);

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    return 0;
}
