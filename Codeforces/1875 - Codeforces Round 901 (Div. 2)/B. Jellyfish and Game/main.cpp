// ﷽
// https://codeforces.com/contest/1875/problem/B

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
    int n, m, k;
    cin >> n >> m >> k;
    int a[n];
    int b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);

    if (b[m - 1] > a[0]) {
        k--;
        swap(a[0], b[m - 1]);
        if (k & 1) {
            sort(a, a + n);
            sort(b, b + m);
            swap(a[n - 1], b[0]);
            cout << accumulate(a, a + n, 0LL) << '\n';
        } else {
            cout << accumulate(a, a + n, 0LL) << '\n';
        }
    } else {
        if (k & 1) {
            cout << accumulate(a, a + n, 0LL) << '\n';
        } else {
            swap(a[n - 1], b[0]);
            cout << accumulate(a, a + n, 0LL) << '\n';
        }
    }
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
