// ﷽
#include <algorithm>
#include <array>
#include <assert.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string.h>
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
int n, m;
int vis[N];
vector<int> adj[N];
vector<int> cycle, st;

void dfs(int i) {
    if (cycle.size()) vis[i] = 2;
    if (vis[i] == 2) return;

    if (vis[i] == 1) {
        // i is in the stack right now
        cycle.push_back(i);
        debug(i, st);
        for (int j = st.size() - 1; st[j] != i; j--)
            cycle.push_back(st[j]);
        cycle.push_back(i);
    }

    vis[i] = 1;
    st.push_back(i);
    for (int c : adj[i])
        if (!cycle.size())
            dfs(c);
    st.pop_back();
    vis[i] = 2;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
    }

    for (int i = 0; i < n; i++) {
        dfs(i);
    }

    if (cycle.empty()) {
        cout << "IMPOSSIBLE\n";
    } else {
        reverse(all(cycle));
        cout << cycle.size() << "\n";
        for (auto i: cycle)
            cout << i + 1 << " ";
    }

    return 0;
}
