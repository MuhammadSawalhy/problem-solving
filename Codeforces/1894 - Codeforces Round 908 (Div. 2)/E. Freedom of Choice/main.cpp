// ﷽
// https://codeforces.com/contest/1894/problem/E

#include <algorithm>
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

void solve() {
    int m;
    cin >> m;

    int n[m], l[m], r[m];
    vector<int> a[m], c[m];
    map<int, int> must_take, fr, can_take_outside, r_sum;

    vector<int> values;
    int mn = 0, mx = 0;

    for (int i = 0; i < m; i++) {
        int len = 0;
        cin >> n[i] >> l[i] >> r[i];
        mn += l[i];
        mx += r[i];
        a[i].resize(n[i]);
        c[i].resize(n[i]);
        for (int j = 0; j < n[i]; j++) {
            cin >> a[i][j];
            values.push_back(a[i][j]);
            r_sum[a[i][j]] += r[i];
        }
        for (int j = 0; j < n[i]; j++) {
            cin >> c[i][j];
            len += c[i][j];
        }
        for (int j = 0; j < n[i]; j++) {
            int mt = max(0ll, l[i] - (len - c[i][j]));
            must_take[a[i][j]] += mt;
            fr[a[i][j]] += c[i][j];
            can_take_outside[a[i][j]] += min(len - c[i][j], r[i]);
        }
    }

    sort(all(values));
    values.resize(unique(all(values)) - values.begin());

    debug(m);
    debug(mn, mx, values);

    auto X = lower_bound(all(values), mn);
    auto Y = upper_bound(all(values), mx);

    if (X == values.end() || *X != mn || *prev(Y) != mx || Y - X != mx - mn + 1) {
        cout << 0 << endl;
        return;
    }

    for (auto x: values) {
        can_take_outside[x] += mx - r_sum[x];
    }

    const ll inf = 1e18;
    ll ans = inf;

    for (auto x: values) {
        if (x < mn || x > mx) continue;
        debug(x, must_take[x]);
        debug(can_take_outside[x]);
        int len = must_take[x] + can_take_outside[x];
        if (len >= x) {
            minit(ans, must_take[x]);
        } else {
            minit(ans, x - can_take_outside[x]);
        }
    }

    cout << ans << endl;
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
