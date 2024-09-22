// ﷽
// https://codeforces.com/contest/2001/problem/C

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

struct DSU {
    vector<int> size, parent;
    int forests;

    DSU(int n) : forests(n) {
        size.assign(n, 1);
        parent.resize(n), iota(all(parent), 0);
    }

    bool connected(int x, int y) { return find(x) == find(y); }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool uni(int x, int y) { // merge x into y
        x = find(x), y = find(y);
        if (x == y) return false;
        forests--;
        parent[x] = y;
        size[y] += size[x];
        return true;
    }
};

void solve() {
    int n;
    cin >> n;

    set<int> rest;

    int a = 1;
    for (int i = 2; i <= n; i++) rest.insert(i);

    vector<pii> edges;
    DSU dsu(n + 1);

    function<void(int, int)> getb = [&](int a, int b) {
        if (dsu.connected(a, b)) return;
        assert(a != b);
        int x;
        cout << "? " << a << ' ' << b << endl;
        cin >> x;

        if (x == b) swap(a, b);
        if (x == a) {
            if (!dsu.connected(a, b)) {
                dsu.uni(a, b);
                edges.emplace_back(a, b);
            }
            rest.erase(a);
            rest.erase(b);
            return;
        }

        getb(a, x);
        getb(b, x);
    };

    while (sz(rest)) {
        getb(a, *rest.begin());
    }

    assert(sz(edges) == n - 1);
    cout << "! ";
    for (auto [a, b]: edges) {
        cout << a << ' ' << b << ' ';
    }
    cout << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
