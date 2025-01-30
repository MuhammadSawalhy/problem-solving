#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

struct BIT {
    int n;
    vector<int> tree;

    BIT(int size) : n(size) { tree.resize(n + 1, 0); }

    void update(int i, int delta) {
        delta = (delta % mod + mod) % mod;
        for (i++; i <= n; i += i & -i) tree[i] = (tree[i] + delta) % mod;
    }

    int sum(int i) {
        int sum = 0;
        for (i++; i > 0; i -= i & -i) (sum += tree[i]) %= mod;
        return sum;
    }

    int query(int l, int r) { return (sum(r) - sum(l - 1) + mod) % mod; }
};

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> vals;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        vals.push_back(a[i].first);
        vals.push_back(a[i].second);
    }

    sort(vals.begin(), vals.end());
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        a[i].first = lower_bound(vals.begin(), vals.end(), a[i].first) - vals.begin();
        a[i].second = lower_bound(vals.begin(), vals.end(), a[i].second) - vals.begin();
    }

    BIT bit(2 * n);
    bit.update(2 * n - 1, 1);
    for (int i = 0; i < n; i++) {
        int f = bit.query(a[i].first, 2 * n - 2);
        int s = bit.query(a[i].second, 2 * n - 1);
        bit.update(a[i].second, s);
        bit.update(2 * n - 1, f);
    }

    cout << bit.query(2 * n - 1, 2 * n - 1) << endl;
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
