#include <bits/stdc++.h>
using namespace std;

int n;
const long long INF = 1e18;
long long adj[50][50];
long long adj2[50][50];

bool dfs(int u, vector<int> &parent, vector<bool> &visited) {
    if (u == n - 1) return true;
    visited[u] = true;

    for (int v = 0; v < n; ++v) {
        if (!visited[v] && adj2[u][v] > 0) {
            parent[v] = u;
            if (dfs(v, parent, visited)) return true;
        }
    }

    return false;
}

long long mx_flow() {
    long long flow = 0;

    vector<int> parent(n);
    vector<bool> visited(n);

    while (true) {
        fill(visited.begin(), visited.end(), false);

        if (!dfs(0, parent, visited)) break;

        long long mn = INF;
        for (int v = n - 1; v != 0; v = parent[v]) {
            int u = parent[v];
            mn = min(mn, adj2[u][v]);
        }

        for (int v = n - 1; v != 0; v = parent[v]) {
            int u = parent[v];
            adj2[u][v] -= mn;
            adj2[v][u] += mn;
        }

        flow += mn;
    }

    return flow;
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int m, x;
    cin >> n >> m >> x;

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c, u--, v--;
        adj[u][v] = c;
    }

    double l = 0, r = 1e9;
    for (int iter = 0; iter < 100; iter++) {
        double mid = (l + r) / 2;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adj2[i][j] = (long long) (adj[i][j] / mid);
        long long flow = mx_flow();
        if (flow >= x) l = mid;
        else r = mid;
    }

    cout << fixed << setprecision(10) << l * x << endl;

    return 0;
}
