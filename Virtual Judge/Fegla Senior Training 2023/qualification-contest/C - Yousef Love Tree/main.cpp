// ﷽
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

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

int n, l;
vector<vector<int>> adj;

int root = 0;
vector<vector<int>> up;
vector<int> v;

int dfs(int node, int p) {
    up[node][0] = p;
    for (int i = 1; i <= l; ++i)
        up[node][i] = up[up[node][i - 1]][i - 1];

    for (int u: adj[node]) {
        v[node] &= dfs(u, node);
    }

    return v[node];
}

int find(int u, int i) {
    int x = 0;
    while (i) {
        if (i & 1)
            u = up[u][x];
        i >>= 1;
        x++;
    }
    return u;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    adj.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p, p--;
        adj[p].push_back(i);
    }

    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    v.assign(n, 0);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    dfs(root, root);

    debug(up[8]);

    while (q--) {
        int u, k;
        cin >> u >> k;
        u--;

        int s = 0, e = l;
        while (e - s > 1) {
            int mid = (s + e) / 2;
            if (v[find(u, mid)] <= k)
                e = mid;
            else
                s = mid;
        }

        debug(u, e, find(u, e));

        if (v[find(u, e)] <= k) {
            cout << find(u, e) + 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
