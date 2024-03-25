// ﷽
// https://atcoder.jp/contests/abc294/tasks/abc294_f

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
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    k = n * m - k + 1;

    int a[n], b[n], c[m], d[m];
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for (int i = 0; i < m; i++) cin >> c[i] >> d[i];

    double l = 0, r = 1;
    for (int iter = 0; iter < 100; iter++) {
        double x = (l + r) / 2;
        double v[m];
        for (int i = 0; i < m; i++) v[i] = -c[i] + x * (c[i] + d[i]);
        sort(v, v + m);

        // a - x * (a + b) < -c + x * (c + d)
        // cnt of concentration < x
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int j = upper_bound(v, v + m, a[i] - x * (a[i] + b[i])) - v;
            cnt += m - j;
        }

        debug(x, cnt);

        if (cnt >= k) r = x;
        else l = x;
    }

    cout << fixed << setprecision(15) << l * 100 << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
