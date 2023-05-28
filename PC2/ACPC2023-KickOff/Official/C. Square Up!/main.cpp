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

struct DSU {
    vector<int> size, parent;
    int forests;

    DSU(int n) {
        forests = n;
        size.assign(n, 1);
        parent.resize(n);
        iota(all(parent), 0);
    }

    bool connected(int x, int y) { return find(x) == find(y); }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool uni(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        forests--;
        parent[y] = x;
        size[x] += size[y];
        return true;
    }
};

const int N = 5e5 + 5;
string board[N];

bool is_good(int i, int j) {
    return i > 0 && j > 0 && board[i][j] == '.' && board[i][j - 1] == '.' && board[i - 1][j] == '.' && board[i - 1][j - 1] == '.';
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    bool found = false;

    DSU dsu(n * m);

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (is_good(i, j)) {
                debug(i, j);
                found = true;
                if (is_good(i - 1, j)) {
                    dsu.uni(i * m + j, (i - 1) * m + j);
                }
                if (is_good(i, j - 1)) {
                    dsu.uni(i * m + j, (i) *m + j - 1);
                }
            }
        }
    }

    int ans = 0;

    if (!found) {
        cout << "0\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, dsu.size[dsu.find(i * m + j)]);
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
