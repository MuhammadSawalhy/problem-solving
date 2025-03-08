#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> adj[N];
int n, removed[N], sz[N];
pair<int, int> node[2 * N];
string s;
array<int, 3> ans;

int dfs_size(int u, int p) {
    sz[u] = 1;
    for (int v: adj[u]) {
        if (v == p || removed[v]) continue;
        sz[u] += dfs_size(v, u);
    }
    return sz[u];
}

int centroid(int u, int p) {
    for (int v: adj[u]) {
        if (v == p || removed[v]) continue;
        if (sz[v] > n / 2) return centroid(v, u);
    }
    return u;
}

void getans(int u, int p, int sum, int depth) {
    sum += s[u] == 'L' ? -1 : +1;

    auto a = node[2 * n - sum];
    if (a.first != -1) {
        ans = max(ans, {a.first + depth, a.second, u});
    }

    for (int v: adj[u]) {
        if (v == p || removed[v]) continue;
        getans(v, u, sum, depth + 1);
    }
}

void add(int u, int p, int sum, int depth) {
    sum += s[u] == 'L' ? -1 : +1;
    node[sum] = max(node[sum], {depth, u});
    for (int v: adj[u]) {
        if (v == p || removed[v]) continue;
        add(v, u, sum, depth + 1);
    }
}

void solve(int u) {
    dfs_size(u, -1);
    n = sz[u];
    int c = centroid(u, -1);
    removed[c] = true;

    for (int i = 0; i < 2 * n; i++) node[i] = {-1, -1};
    node[n + (s[c] == 'L' ? -1 : +1)] = {1, c};

    for (auto v: adj[c]) {
        if (removed[v]) continue;
        getans(v, c, n, 1);
        add(v, c, n + (s[c] == 'L' ? -1 : +1), 2);
    }

    for (auto v: adj[c]) {
        if (removed[v]) continue;
        solve(v);
    }
}

vector<int> path;
void print_path(int u, int p) {
    path.push_back(u);
    if (u == ans[2]) {
        for (auto v: path) cout << v + 1 << ' ';
        exit(0);
    }
    for (auto v: adj[u]) {
        if (v == p) continue;
        print_path(v, u);
    }
    path.pop_back();
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    freopen("shoes.in", "r", stdin);
    freopen("shoes.out", "w", stdout);
    cin >> n >> s;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve(0);

    cout << ans[0] << endl;
    if (ans[0] > 0) print_path(ans[1], -1);

    return 0;
}
