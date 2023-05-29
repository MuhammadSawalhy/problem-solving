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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> adj[n];
    vector<int> cnt(n);
    vector<int> ans(n);

    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b, a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    function<void(int, int)> dfs = [&](int i, int p) {
        cnt[i] = 1;
        for (auto j: adj[i]) {
            if (j == p) continue;
            dfs(j, i);
            cnt[i] += cnt[j];
            ans[i] += ans[j] + cnt[j];
        }
    };

    function<void(int, int, int, int)> dfs2 = [&](int i, int p, int outer, int outer_cnt) {
        for (auto j: adj[i]) {
            if (j == p) continue;
            dfs2(j, i, outer + outer_cnt + ans[i] - ans[j] - cnt[j] + cnt[i] - cnt[j], outer_cnt + cnt[i] - cnt[j]);
        }
        ans[i] += outer;
    };

    dfs(0, 0);
    dfs2(0, 0, 0, 0);

    for (auto i: ans)
        cout << i << ' ';

    return 0;
}
