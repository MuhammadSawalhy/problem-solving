// ﷽
#include <bits/stdc++.h>
#include <queue>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

void solve() {
    int n, m; cin >> n >> m; ll a[n], c[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> c[i];

    priority_queue<int> pq;
    sort(a, a + n);
    sort(c, c + m, greater<int>());
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && a[i] == a[j]) j++;
        pq.push(j - i);
        i = j;
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (pq.empty()) break;
        int x = pq.top();
        pq.pop();
        // split max (x) into best possible locations (if c[i] < x)
        // to get minimum excess, which will result in better
        ans += min(x, c[i]);
        if (c[i] < x)
            pq.push(x - c[i]);
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
