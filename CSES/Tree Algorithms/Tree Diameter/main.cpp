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

int n, ans;
const int N = 2e5;
vector<int> adj[N];
int mxd = 0, b;

void dfs1(int i, int p, int d = 0) {
    if (d > mxd) {
        mxd = d;
        b = i;
    }
    for (auto j : adj[i]) {
        if (j == p) continue;
        dfs1(j, i, d + 1);
    }
}

void dfs2(int i, int p, int d = 0) {
    if (d > mxd) {
        mxd = d;
        b = i;
    }
    for (auto j : adj[i]) {
        if (j == p) continue;
        dfs2(j, i, d + 1);
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

    dfs1(0, 0);
    mxd = 0;
    dfs2(b, b);

    cout << mxd;

    return 0;
}
