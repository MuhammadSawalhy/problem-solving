// ﷽
// https://codeforces.com/contest/1852/problem/C
// Codeforces -> Codeforces Round 887 (Div. 1) -> C. Ina of the Mountain

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

void solve() {
    int n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;

    int cur = 0, x, y, prev = 0;
    for (int i = 0; i < n; i++) {
        cin >> x, x %= k, y = x;
        x -= prev;
        if (x == 0) continue;
        if (x > 0) x -= k;
        cur += x;
        pq.push(x + k);
        if (cur < 0) {
            debug(i);
            cur += k;
            ans += pq.top();
            pq.pop();
        }
        prev = y;
    }

    cout << ans << '\n';
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
