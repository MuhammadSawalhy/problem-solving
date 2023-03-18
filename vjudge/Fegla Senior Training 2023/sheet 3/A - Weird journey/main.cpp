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
bool vis[N], valid[N];
vector<int> adj[N];
long long loops, cnt[N];

void dfs(int i) {
    if (vis[i]) return;
    vis[i] = true;
    for (auto j: adj[i])
        dfs(j);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b, a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        valid[a] = valid[b] = true;
        if (a == b)
            loops++;
        else
            cnt[a]++, cnt[b]++;
    }

    dfs(0);
    bool con = true;

    for (int i = 0; i < n; i++)
        if (valid[i]) {
            dfs(i);
            break;
        }

    for (int i = 0; i < n; i++)
        con &= vis[i] || !valid[i];

    if (!con) {
        cout << "0\n";
        return 0;
    }

    long long ans = loops * (m - 1) - loops * (loops - 1) / 2;

    for (int i = 0; i < n; i++) {
        ans += 1LL * (cnt[i]) * (cnt[i] - 1) / 2;
    }

    cout << ans << '\n';
    return 0;
}
