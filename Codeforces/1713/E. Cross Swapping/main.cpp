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

void solve() {
    int n;
    cin >> n;

    DSU dsu(n * 2);

    int mat[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    auto canbesame = [&] (int i, int j) -> bool {
        return !dsu.connected(i * 2, j * 2 + 1);
    };

    auto canbediff = [&] (int i, int j) -> bool {
        return !dsu.connected(i * 2, j * 2);
    };

    auto makesame = [&] (int i, int j) -> void {
        dsu.uni(i * 2, j * 2);
        dsu.uni(i * 2 + 1, j * 2 + 1);
    };

    auto makediff = [&] (int i, int j) -> void {
        dsu.uni(i * 2 + 1, j * 2);
        dsu.uni(i * 2, j * 2 + 1);
    };

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mat[i][j] < mat[j][i]) {
                if (canbesame(i, j)) makesame(i, j);
            } else if (mat[i][j] > mat[j][i]) {
                if (canbediff(i, j)) makediff(i, j);
            }
        }
    }

    vector<int> flips(n, -1);

    for (int i = 0; i < n; i++) {
        assert(!dsu.connected(i * 2, i * 2 + 1));
        if (flips[i] == -1) flips[i] = 0;
        for (int j = i + 1; j < n; j++) {
            if (dsu.connected(i * 2, j * 2)) {
                assert(flips[j] == -1 || flips[j] == flips[i]);
                flips[j] = flips[i];
            }
            if (dsu.connected(i * 2 + 1, j * 2)) {
                assert(flips[j] == -1 || flips[j] == (flips[i] ^ 1));
                flips[j] = flips[i] ^ 1;
            }
        }
    }

    debug(flips);
    for (int i = 0; i < n; i++) {
        assert(~flips[i]);
        for (int j = i + 1; j < n; j++) {
            if (flips[i] ^ flips[j]) {
                swap(mat[i][j], mat[j][i]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
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
