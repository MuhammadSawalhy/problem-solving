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

struct dsu {
    vector<int> rank, parent;
    int forests;

    dsu(int n) {
        forests = n;
        rank = vector<int>(n);
        parent = vector<int>(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    bool connected(int x, int y) { return find(x) == find(y); }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool uni(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return false;
        if (rank[y] > rank[x])
            swap(x, y);
        forests--;
        parent[y] = x;
        if (rank[x] == rank[y])
            rank[x]++;
        return true;
    }
};

int n, m;

int dfs(int i, vector<bool> &vis, vector<int> &deg, vector<int> adj[]) {
    debug(i);
    vis[i] = true;
    int cnt = 0;
    for (auto j : adj[i]) {
        if (vis[j] || deg[j] != 2) continue;
        cnt += dfs(j, vis, deg, adj) + 1;
    }
    return cnt;
}

bool check_fours(vector<int> &deg, vector<int> adj[], int k) {
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        if (deg[i] != 4) continue;
        if (dfs(i, vis, deg, adj) != k - 1) return false;
    }
    return true;
}

bool check_fours(vector<int> &deg, vector<int> adj[]) {
    for (int i = 1; i <= n; i++) {
        if (deg[i] != 4) continue;
        int twos = 0, fours = 0;
        for (auto child : adj[i]) {
            if (deg[child] == 4) fours++;
            else twos++;
        }
        if (fours != 2 || twos != 2) return false;
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] != 2) continue;
        int twos = 0, fours = 0;
        for (auto child : adj[i]) {
            if (deg[child] == 4) fours++;
            else twos++;
        }
        if (fours == 0 && twos == 2) continue;
        if (twos == 1 && fours == 1) continue;
        return false;
    }
    return true;
}

void solve() {
    cin >> n >> m;

    dsu uf(n + 1);

    vector<int> adj[n + 1];
    vector<int> deg(n + 1);
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        deg[a]++, deg[b]++;
        uf.uni(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 2; i <= n; i++)
        if (!uf.connected(1, i)) return cout << "NO\n", void();

    int twos = 0;
    int fours = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 2)
            twos++;
        else if (deg[i] == 4)
            fours++;
        else
            return cout << "NO\n", void();
    }

    int sq = sqrtl(n);
    if (sq * sq == n && fours == sq && check_fours(deg, adj, sq) && check_fours(deg, adj)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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
