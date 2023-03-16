// ﷽
#include <bits/stdc++.h>

using namespace std;

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

const int N = 2e5 + 1;
vector<int> adj[N];
int n, cnt = 0, ans[N];

void dfs(int i, int p, int x, int y) {
    int childcolor = 0;
    cnt = max(cnt, x);
    for (auto child : adj[i]) {
        if (child == p) continue;
        childcolor++;
        while (childcolor == x || childcolor == y) childcolor++;
        ans[child] = childcolor;
        dfs(child, i, childcolor, x);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;

    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ans[0] = 1;
    dfs(0, 0, 1, 0);

    cout << cnt << '\n';
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];

    return 0;
}
