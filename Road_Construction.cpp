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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    int mx = 1;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        dsu.uni(a, b);
        mx = max(mx, dsu.size[dsu.find(a)]);
        cout << dsu.forests << ' ' << mx << endl;
    }

    return 0;
}
