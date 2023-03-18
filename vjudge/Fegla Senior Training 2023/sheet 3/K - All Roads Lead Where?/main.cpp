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

vector<int> adj[26];

bool dfs(int i, int p, int t, vector<int> &path) {
    path.push_back(i);
    if (i == t) {
        return true;
    }
    for(auto j : adj[i]) {
        if (j == p) continue;
        if (dfs(j, i, t, path)) {
            return true;
        }
    }

    path.pop_back();
    return false;
}

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < 26; i++) 
        adj[i].clear();

    string u, v;
    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        adj[u[0] - 'A'].push_back(v[0] - 'A');
        adj[v[0] - 'A'].push_back(u[0] - 'A');
    }

    while (q--) {
        cin >> u >> v;
        vector<int> path;
        dfs(u[0] - 'A', -1, v[0] - 'A', path);
        for (int i : path)
            cout << char('A' + i);
        cout << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve(), t && (cout << endl);

    return 0;
}
