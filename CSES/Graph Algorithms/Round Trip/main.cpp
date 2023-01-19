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

const int N = 1e5;
vector<int> adj[N], parent(N, -1);
bool ok = false;
int e = -1, s = -1;

void dfs(int i, int p) {
    if (ok) return;
    if (~parent[i]) {
        // cycle
        ok = true, s = i, e = p;
        debug("cycle", ok, s, e);
        return;
    }
    parent[i] = p;
    for (int a : adj[i]) if (a != p) dfs(a, i);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        // dfs each connect component alone
        if (parent[i] == -1) dfs(i, -2);
        if (ok) break;
    }

    if (ok) {
        assert(~e);
        vector<int> ans;
        while (e != s) {
            ans.push_back(e);
            e = parent[e];
        }
        cout << ans.size() + 2 << endl << s + 1 << " ";
        for (auto i: ans)
            cout << i + 1 << " ";
        cout << s + 1 << endl;
    } else
        cout << "IMPOSSIBLE";

    return 0;
}
