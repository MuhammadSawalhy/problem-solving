#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

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
    vector<int> a(n);
    vector<int> d(n);
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        dsu.uni(a[i], i);
    }

    vector<bool> done(n);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> d[i];
        d[i]--;
        d[i] = dsu.find(d[i]);
        if (done[d[i]] == false) {

            ans += dsu.size[d[i]];
            done[d[i]] = 1;
        }
        cout << ans << ' ';
    }
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
