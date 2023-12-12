// ﷽
// https://atcoder.jp/contests/abc327/tasks/abc327_d

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
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

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

    int s[m], t[m];
    for (int i = 0; i < m; i++) cin >> s[i], s[i]--;
    for (int i = 0; i < m; i++) cin >> t[i], t[i]--;

    DSU dsu(2 * n);


    for (int i = 0; i < m; i++) {
        dsu.uni(s[i], t[i] + n);
        dsu.uni(s[i] + n, t[i]);
    }

    for (int i = 0; i < n; i++) {
        if (dsu.connected(i, i + n)) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
