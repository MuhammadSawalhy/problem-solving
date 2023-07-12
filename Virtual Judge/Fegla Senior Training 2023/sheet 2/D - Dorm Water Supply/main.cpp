// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

const int N = 1001;
pair<int, int> adj[N];
bool vis[N], in[N], out[N], cycle;

pair<int, int> dfs(int i) {
    if (vis[i]) {
        cycle = true;
        return {0, 0};
    }

    int diam = 1e9;
    int tap = i;
    vis[i] = true;

    if (out[i]) {
        auto res = dfs(adj[i].first);
        diam = min(adj[i].second, res.second);
        tap = res.first;
    }

    return {tap, diam};
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, p;

    cin >> n >> p;

    for (int i = 0, a, b, d; i < p; i++) {
        cin >> a >> b >> d;
        adj[a] = {b, d};
        out[a] = true;
        in[b] = true;
    }

    vector<array<int, 3>> ans;
    for (int i = 1; i <= n; i++) {
        if (!out[i] || in[i]) continue;
        cycle = false;
        auto res = dfs(i);
        if (res.first == i || cycle) continue;
        ans.push_back({i, res.first, res.second});
    }

    cout << ans.size() << '\n';
    for (auto [tank, tap, diam]: ans) {
        cout << tank << ' ' << tap << ' ' << diam << '\n';
    }

    return 0;
}
