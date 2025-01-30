#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> adj[N];
bool vis[N];

pair<int, int> solve(int u, int p) {
    vis[u] = true;
    int f = -1, s = -1;

    vector<pair<int, int>> ch;
    for (auto v: adj[u]) {
        if (v == p) continue;
        ch.push_back(solve(v, u));
    }

    if (ch.size() == 0) f = s = 1;
    else if (ch.size() == 1) {
        s = f = min(ch[0].second + 1, ch[0].first);
    } else {
        vector<int> order(ch.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
            return ch[i].first - ch[i].second < ch[j].first - ch[j].second;
        });
        int sum = 0;
        for (int i = 0; i < ch.size(); i++) sum += ch[i].second;
        s = sum + 1;
        s = min(s, sum - ch[order[0]].second + ch[order[0]].first);
        s = min(s, sum - ch[order[0]].second - ch[order[1]].second + ch[order[0]].first + ch[order[1]].first - 1);

        f = sum + 1;
        f = min(f, sum - ch[order[0]].second + ch[order[0]].first);
    }

    assert(f != -1 && s != -1);
    return {f, s};
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v, u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) cnt += solve(i, i).second;
        }


        int ans = n + cnt - 1;
        cout << ans << endl;

        for (int i = 0; i < n; i++) adj[i].clear(), vis[i] = false;
    }

    return 0;
}
