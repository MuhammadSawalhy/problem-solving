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

const int N = 1e5;
vector<int> adj[N];
bool hascat[N];
int n, m, ans;

void dfs(int i, int p, int cats, int mxcats) {
    bool leaf = true;
    if (hascat[i])
        cats++;
    else
        cats = 0;
    mxcats = max(mxcats, cats);
    for (auto child: adj[i]) {
        if (child == p) continue;
        leaf = false;
        dfs(child, i, cats, mxcats);
    }
    if (leaf && mxcats <= m)
        ans++;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> hascat[i];
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, 0, 0, 0);

    cout << ans << endl;

    return 0;
}
