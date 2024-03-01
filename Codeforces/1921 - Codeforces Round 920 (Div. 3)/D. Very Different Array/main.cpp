// ﷽
// https://codeforces.com/contest/1921/problem/D

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
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    int ans = 0;
    // try all less
    int A = 0;
    for (int i = 0; i < n; i++) {
        A += abs(a[i] - b[i]);
    }

    // try all greater
    int B = 0;
    for (int i = 0; i < n; i++) {
        B += abs(a[i] - b[m - i - 1]);
    }

    // try a point of flip
    int ps_b[m + 1];
    ps_b[0] = 0;
    for (int i = 0; i < m; i++)
        ps_b[i + 1] = ps_b[i] + b[i];

    int ps_a[n + 1];
    ps_a[0] = 0;
    for (int i = 0; i < n; i++)
        ps_a[i + 1] = ps_a[i] + a[i];

    debug(n, m);
    debug_itr(a, n);
    for (int i = 0; i < n - 1; i++) {
        // choose to the left such that min(choosen) >= a[i] and to the left such that max(choosen) <= a[i];
        int j = lower_bound(b, b + m, a[i]) - b;
        int k = upper_bound(b, b + m, a[i]) - b;
        int r = m - i - 1;
        if (r < j) continue;
        int x = ps_b[m] - ps_b[r] - ps_a[i + 1];
        int y = ps_a[n] - ps_a[i + 1] - ps_b[n - i - 1];
        debug(i, x, y);
        maxit(ans, x + y);
    }

    cout << max({ans, A, B}) << endl;
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
