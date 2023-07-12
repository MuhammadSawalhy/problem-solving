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

// Credits to: 7oSkaaa
struct Node {
    int x, y;
    Node *r, *l, *u, *d;

    Node(int X = -1, int Y = -1, Node *R = nullptr, Node *L = nullptr, Node *U = nullptr, Node *D = nullptr) {
        x = X, y = Y, r = R, l = L, u = U, d = D;
    }
};

int n, m;
vector<string> grid;
vector<vector<Node>> nodes;
vector<vector<bool>> vis;

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y];
}

int dfs(Node *root) {
    if (root == nullptr) return 0;
    int points = 1, r = root->x, c = root->y;

    // remove
    if (root->r != nullptr) root->r->l = root->l;
    if (root->l != nullptr) root->l->r = root->r;
    if (root->u != nullptr) root->u->d = root->d;
    if (root->d != nullptr) root->d->u = root->u;

    if (grid[r][c] == 'U') points += dfs(root->u);
    else if (grid[r][c] == 'D') points += dfs(root->d);
    else if (grid[r][c] == 'L') points += dfs(root->l);
    else if (grid[r][c] == 'R') points += dfs(root->r);

    // return it back
    if (root->r != nullptr) root->r->l = root;
    if (root->l != nullptr) root->l->r = root;
    if (root->u != nullptr) root->u->d = root;
    if (root->d != nullptr) root->d->u = root;

    return points;
}

void solve() {
    cin >> n >> m;
    grid = vector<string>(n);
    nodes = vector<vector<Node>>(n, vector<Node>(m));
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    // assign l and r for each node
    for (int i = 0; i < n; i++) {
        Node *prev = nullptr;
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') continue;
            nodes[i][j] = Node(i, j);
            if (prev != nullptr) {
                nodes[i][j].l = prev;
                prev->r = &nodes[i][j];
            }
            prev = &nodes[i][j];
        }
    }

    // assign u and d for each node
    for (int j = 0; j < m; j++) {
        Node *prev = nullptr;
        for (int i = 0; i < n; i++) {
            if (grid[i][j] == '.') continue;
            if (prev != nullptr) {
                nodes[i][j].u = prev;
                prev->d = &nodes[i][j];
            }
            prev = &nodes[i][j];
        }
    }

    int max_points = 0, number_of_nodes = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') continue;
            vis = vector<vector<bool>>(n, vector<bool>(m));
            vis[i][j] = true;
            int points = dfs(&nodes[i][j]);
            if (points > max_points) {
                max_points = points;
                number_of_nodes = 1;
            } else if (points == max_points) {
                number_of_nodes++;
            }
        }
    }

    cout << max_points << ' ' << number_of_nodes << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
