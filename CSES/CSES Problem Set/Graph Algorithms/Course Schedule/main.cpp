// ﷽
#include <algorithm>
#include <array>
#include <assert.h>
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

const int N = 1e5;
vector<int> adj[N];
int n, m;
bool vis[N];
vector<int> topsort;

void dfs(int i) {
    if (vis[i]) return;
    vis[i] = true;
    for (int child: adj[i])
        dfs(child);
    topsort.push_back(i);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
        dfs(i);

    int ind[n];
    for (int i = 0; i < n; i++) {
        ind[topsort[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j: adj[i]) {
            if (ind[j] > ind[i]) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for (auto i: topsort) {
        cout << i + 1 << " ";
    }

    return 0;
}
