// ﷽
#include <algorithm>
#include <array>
#include <assert.h>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string.h>
#include <utility>
#include <vector>

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

const int N = 2e5;
vector<int> adj[N];
bool vis[N];

bool dfs(int i, int p) {
    if (vis[i]) return true;
    vis[i] = true;

    bool ret = adj[i].size() == 2;
    for (auto child: adj[i]) {
        ret &= dfs(child, i);
    }

    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        char c;
        cin >> u >> c >> v >> c;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cycle = 0, non = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        if (dfs(i, i)) {
            cycle++;
        } else {
            non++;
        }
    }

    cout << cycle << " " << non << endl;

    return 0;
}
