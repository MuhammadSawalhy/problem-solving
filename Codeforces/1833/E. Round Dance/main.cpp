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
    int n;
    vector<int> parent, size;
    DSU(int n): n(n) {
        parent.resize(n);
        iota(all(parent), 0);
        size.assign(n, 1);
    }
    
    int find(int x) {
        return parent[x] = (parent[x] == x ? x : find(parent[x]));
    }
    
    bool uni(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        parent[y] = x;
        size[x] += size[y];
        return true;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n, -1), deg(n);
    
    DSU dsu(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        if (a[a[i]] != i) {
            deg[i]++;
            deg[a[i]]++;
        }
        dsu.uni(i, a[i]);
    }

    vector<bool> vis(n);
    map<int, vector<int>> groups;
    
    for (int i = 0; i < n; i++) {
        groups[dsu.find(i)].push_back(i);
    }

    int closed = 0, open = 0;
    
    for (auto [x, g] : groups) {
        
        int one = 0, two = 0;
        for (auto i : g) {
            assert(deg[i] == 2 || deg[i] == 1);
            if (deg[i] == 2) two++;
            else one++;
        }
        assert(one == 2 || one == 0);
        if (one == 2) open++;
        else closed++;
    }

    cout << closed + (open > 0) << ' ' << closed + open << '\n';
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

