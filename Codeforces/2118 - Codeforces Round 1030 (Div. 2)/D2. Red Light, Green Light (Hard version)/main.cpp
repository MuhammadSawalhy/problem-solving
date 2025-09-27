#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    int p[n], d[n];
    for (auto &x: p) cin >> x;
    for (auto &x: d) cin >> x;

    // build the graph

    int nxt[n][2];
    memset(nxt, -1, sizeof nxt);

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int id = (d[i] + p[i]) % k;
        if (mp.count(id)) {
            // left
            nxt[i][1] = mp[id];
        }
        mp[id] = i;
    }

    int q;
    cin >> q;
    pair<int, int> a[q];
    for (int i = 0; i < q; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    int q_node[q];
    memset(q_node, -1, sizeof q_node);
    sort(a, a + q);

    mp.clear();
    int j = q - 1;

    for (int i = n - 1; i >= 0; i--) {
        while (j >= 0 && p[i] < a[j].first) {
            int id = (k - a[j].first % k) % k;
            if (mp.count(id))
                q_node[a[j].second] = mp[id];
            j--;
        }

        int id = ((d[i] - p[i]) % k + k) % k;
        if (mp.count(id)) {
            // right
            nxt[i][0] = mp[id];
        }
        mp[id] = i;
    }

    while (j >= 0) {
        int id = (k - a[j].first % k) % k;
            q_node[a[j].second] = mp[id];
        j--;
    }

    int ans[n][2];
    int state[n][2];
    memset(ans, -1, sizeof ans);
    memset(state, 0, sizeof state);

    function<bool(int, int)> dfs = [&](int i, int dir) -> bool {
        if (ans[i][dir] != -1) return ans[i][dir];
        assert(state[i][dir] != 2);

        if (state[i][dir] == 1) {
            state[i][dir] = 2;
            return ans[i][dir] = 0;
        }

        if (nxt[i][dir] == -1) {
            state[i][dir] = 2;
            return ans[i][dir] = 1;
        }

        state[i][dir] = 1;

        int sub = dfs(nxt[i][dir], dir ^ 1);

        state[i][dir] = 2;
        ans[i][dir] = sub;
        return sub;
    };

    for (int i = 0; i < q; i++) {
        int node = q_node[i];
        debug(i, node);
        if (node == -1) {
            cout << "YES\n";
            continue;
        }
        if (dfs(node, 1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("-----", t);
        solve();
    }

    return 0;
}
