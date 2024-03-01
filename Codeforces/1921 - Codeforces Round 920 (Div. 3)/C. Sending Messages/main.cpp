// ﷽
// https://codeforces.com/contest/1921/problem/C

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
    int n, f, a, b;
    cin >> n >> f >> a >> b;
    int m[n + 1];
    m[0] = 0;
    for (int i = 1; i <= n; i++) cin >> m[i];
    debug(n, f, a, b);

    for (int i = 1; i <= n; i++) {
        f -= min(b, (m[i] - m[i - 1]) * a);
        debug(i, f);
        if (f <= 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
