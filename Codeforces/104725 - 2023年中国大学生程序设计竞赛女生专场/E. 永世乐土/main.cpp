#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 33;
int cnt[N];
double p[N], ans = 0;
bool adj[N][N];
int n, m, k;
unordered_set<int> mp[N];

void dfs(int i, int vis, int step, double cur) {
    if (vis >> i & 1 ^ 1) cur += cnt[i] * p[step];
    ans = max(ans, cur);
    vis |= 1 << i;
    if (step > 20 || mp[step].count(vis)) return;
    mp[step].insert(vis);
    for (int j = 0; j < n; j++) {
        if (adj[i][j] && (vis >> j & 1) == 0) {
            dfs(j, vis, step + 1, cur);
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u][v] = adj[v][u] = 1;
    }

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        cnt[--x]++;
    }

    p[0] = p[1] = 1;

    for (int i = 2; i <= n; i++) {
        int rem = n - i + 2;
        p[i] = p[i - 1] * (1.0 - 1.0 / rem);
    }

    dfs(0, 0, 0, 0);

    cout << fixed << setprecision(9) << ans << endl;

    return 0;
}
