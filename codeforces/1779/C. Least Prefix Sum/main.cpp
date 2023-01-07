// ﷽
// 11 جُمادى الآخرة 1444
// Jan 03, 2023
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n];
    ll ps[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ps[i] = a[i];
        if (i > 0)
            ps[i] += ps[i - 1];
    }

    ll s = ps[m - 1];
    int ans = 0;
    priority_queue<int> qu;
    ll d = 0;

    debug(n, m);
    for (int i = m - 1; i >= 0; i--) {
        while (ps[i] < s) {
            int t = qu.top();
            s -= 2 * t;
            ans++;
            qu.pop();
            debug("<-", i, s);
        }
        qu.push(a[i]);
    }

    priority_queue<int> q;
    s = ps[m - 1];
    d = 0;

    for (int i = m; i < n; i++) {
        q.push(-a[i]);
        while (ps[i] + d < s) {
            int t = q.top();
            d += 2 * t;
            ans++;
            q.pop();
            debug("->", i, d);
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
