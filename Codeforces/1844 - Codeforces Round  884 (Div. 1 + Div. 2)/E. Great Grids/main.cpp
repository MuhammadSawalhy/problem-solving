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

#define ll long long
#define int long long
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

int n, m, k;
vector<array<int, 4>> cond;

int ind(int a, int b) {
    return a * m + b;
}

bool valid(array<char, 4> c) {
    return c[0] != c[1] && c[2] != c[3] && c[0] != c[2] && c[1] != c[3] && (c[0] == c[3]) != (c[1] == c[2]);
};

void check(int i, int j, vector<char> &vec) {
    if (i == n && j == m) {
        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j + 1 < m; j++) {
                if (!valid({vec[ind(i, j)], vec[ind(i + 1, j)], vec[ind(i, j + 1)], vec[ind(i + 1, j + 1)]})) {
                    return;
                }
            }
        }

        for (int i = 0; i < k; i++) {
            if (vec[ind(cond[i][0], cond[i][1])] != vec[ind(cond[i][2], cond[i][3])]) {
                return;
            }
        }

        debug(vec);
        exit(0);
        return;
    }

    for (int c = 0; c < 3; c++) {
        vec.push_back("ABC"[c]);
        if (i == n) check(0, j + 1, vec);
        else check(i + 1, j, vec);
        vec.pop_back();
    }
}


void solve() {
    cin >> n >> m >> k;
    cond.clear();

    DSU dsu(n * m);

    for (int i = 0, a, b, c, d; i < k; i++) {
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        cond.push_back({a, b, c, d});
        dsu.uni(ind(a, b), ind(c, d));
    }

    for (int i = 0; i + 1 < n; i++)
        for (int j = 0; j + 1 < m; j++) {
            if (dsu.connected(ind(i, j), ind(i + 1, j + 1)) && dsu.connected(ind(i, j + 1), ind(i + 1, j))) {
                cout << "NO\n";
                return;
            }
        }

    cout << "YES\n";
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
