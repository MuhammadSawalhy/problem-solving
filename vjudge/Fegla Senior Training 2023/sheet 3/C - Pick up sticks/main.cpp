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

const int N = 1e6;
int n, m;
vector<int> adj[N];
vector<int> topsort;
vector<bool> vis(N);

void dfs(int i) {
    if (vis[i]) return;
    vis[i] = true;
    for (auto child : adj[i])
        dfs(child);
    topsort.push_back(i);
}

void solve() {
    topsort.clear();
    
    for (int i = 0; i < n; i++)
        adj[i].clear(), vis[i] = false;

    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b, a--, b--;
        adj[a].push_back(b);
    }

    for (int i = 0; i < n; i++)
        dfs(i);

    reverse(all(topsort));

    vector<int> ind(n);
    for (int i = 0; i < n; i++)
        ind[topsort[i]] = i;
    for (int i = 0; i < n; i++) {
        for (int j : adj[i]) {
            if (ind[j] < ind[i]) {
                return cout << "IMPOSSIBLE\n", void();
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << topsort[i] + 1 << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (cin >> n >> m, n)
        solve();

    return 0;
}
