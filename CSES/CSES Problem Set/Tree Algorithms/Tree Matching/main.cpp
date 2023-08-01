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

const int N = 2e5;
int n, ans;
bool done[N];
vector<int> adj[N];

void dfs(int i, int p) {
    for (auto j : adj[i]) {
        if (j == p) continue;
        dfs(j, i);
        if (!done[i] && !done[j])
            ans++, done[i] = done[j] = true;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b, a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, 0);

    cout << ans;

    return 0;
}
