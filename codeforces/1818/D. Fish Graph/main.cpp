// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

const int N = 2002;
vector<int> adj[N];
bool vis[N], is_adj[N];
vector<int> path;
int n, m;

bool dfs(int i, int p, int t) {
    if (vis[i]) return false;
    vis[i] = true;
    path.push_back(i);

    if (is_adj[i]) return true;

    for (auto j: adj[i]) {
        if (j == p) continue;
        if (dfs(j, i, t)) return true;
    }

    path.pop_back();
    return false;
}

vector<int> get_fins(int i) {
    vector<int> fins;
    set<int> s(all(path));
    for (auto j: adj[i]) {
        if (fins.size() == 2) break;
        if (!s.count(j))
            fins.push_back(j);
    }
    assert(fins.size() == 2);
    return fins;
}

bool try_someone(int i) {
    path.clear();
    memset(vis, 0, sizeof(vis[0]) * n);
    memset(is_adj, 0, sizeof(is_adj[0]) * n);
    for (auto j: adj[i]) {
        is_adj[j] = true;
    }
    for (auto j: adj[i]) {
        is_adj[j] = false;
        if (dfs(j, i, i)) {
            cout << "YES\n";
            auto fins = get_fins(i);
            cout << path.size() + 3 << '\n';
            cout << i + 1 << ' ' << fins[0] + 1 << '\n';
            cout << i + 1 << ' ' << fins[1] + 1 << '\n';
            cout << i + 1 << ' ' << path[0] + 1 << '\n';
            for (int i = 1; i < path.size(); i++)
                cout << path[i - 1] + 1 << ' ' << path[i] + 1 << '\n';
            cout << path.back() + 1 << ' ' << i + 1 << '\n';
            return true;
        }
        is_adj[j] = true;
    }
    return false;
}

void solve() {
    cin >> n >> m;

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() >= 4 && try_someone(i)) {
            ok = true;
            break;
        }
    }

    if (!ok)
        cout << "NO\n";

    for (int i = 0; i < n; i++)
        adj[i].clear();
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
