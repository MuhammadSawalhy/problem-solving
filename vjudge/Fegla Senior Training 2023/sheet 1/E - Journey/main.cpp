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

const int N = 1e5;
vector<int> adj[N];
int n;
double ev = 0;

void dfs(int i, int p, double prob, int l) {
    bool leaf = true;
    for (auto child : adj[i]) {
        if (child == p) continue;
        leaf = false;
        dfs(child, i, prob / (adj[i].size() - (i != 0)), l + 1);
    }
    if (leaf)
        ev += prob * l, debug(l, prob);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;

    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, 0, 1, 0);

    cout << fixed << setprecision(15) << ev << endl;

    return 0;
}
