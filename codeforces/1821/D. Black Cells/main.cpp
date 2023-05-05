// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

void solve() {
    int n, k;
    cin >> n >> k;

    int l[n], r[n], s[n];
    for (int i = 0; i < n; i++)
        cin >> l[i];
    for (int i = 0; i < n; i++)
        cin >> r[i], s[i] = r[i] - l[i] + 1;

    priority_queue<int, vector<int>, greater<int>> qu;

    ll sum = 0;
    ll ans = 1e12;
    for (int i = 0; i < n; i++) {
        sum += s[i];

        while (qu.size() && sum - qu.top() >= k && qu.top() < 2) {
            sum -= qu.top();
            qu.pop();
        }

        qu.push(s[i]);

        if (sum >= k) {
            ll x = max(l[i], l[i] + (k - (sum - s[i])) - 1);
            ans = min(ans, (ll) qu.size() * 2 + x);
        }
    }

    if (ans == 1e12) ans = -1;
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
