// ﷽
#include <bits/stdc++.h>

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

struct union_find {
    vector<int> rank, parent;
    int forests;

    union_find(int n) {
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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    union_find uf(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        uf.uni(a, b);
    }

    cout << uf.forests - 1 << endl;
    for (int i = 1; i < n; i++) {
        if (!uf.connected(i, i - 1)) {
            uf.uni(i, i - 1);
            cout << i << " " << i + 1 << endl;
        }
    }

    return 0;
}
