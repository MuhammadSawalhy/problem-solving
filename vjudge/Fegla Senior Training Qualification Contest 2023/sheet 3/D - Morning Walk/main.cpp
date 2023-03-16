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

const int N = 200;
int n, m;
bool vis[N];
vector<int> adj[N];

int dfs(int i) {
    if (vis[i]) return 0;
    vis[i] = true;
    int cnt = 0;
    for (auto j: adj[i]) {
        cnt += dfs(j) + 1;
    }
    return cnt;
}

void solve() {
    if(m == 0) {
        cout << "Not Possible\n";
        return;
    }

    vector<int> deg(n);

    for (int i = 0; i < n; i++) {
        adj[i].clear();
        vis[i] = false;
    }

    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        deg[a]++, deg[b]++;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int odds = 0;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        int cnt = dfs(i) / 2;
        debug(i, cnt);
        ok &= cnt == 0 || cnt == m;
        odds += deg[i] & 1;
    }

    ok &= odds == 0;

    if (ok) {
        cout << "Possible\n";
    } else {
        cout << "Not Possible\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (cin >> n >> m)
        solve();

    return 0;
}
