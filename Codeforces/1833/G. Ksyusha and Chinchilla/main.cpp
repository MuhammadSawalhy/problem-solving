// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

void solve() {
    int n;
    cin >> n;

    set<pair<int, int>> adj[n];
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        adj[u].insert({v, i});
        adj[v].insert({u, i});
    }

    vector<int> cnt(n);

    vector<int> ans;

    function<void(int, int, int)> dfs = [&](int i, int p, int e) {
        cnt[i] = 1;
        for (auto [j, e]: adj[i]) {
            if (j == p) continue;
            dfs(j, i, e);
            cnt[i] += cnt[j];
        }

        if (cnt[i] == 3) {
            cnt[i] = 0;
            ans.push_back(e);
        }
    };

    dfs(0, 0, -1);

    if (ans.size() == 0 || ans.back() != -1) {
        cout << -1 << endl;
        return;
    }

    ans.pop_back();

    cout << ans.size() << endl;
    for (auto i: ans)
        cout << i + 1 << " ";
    cout << endl;
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
