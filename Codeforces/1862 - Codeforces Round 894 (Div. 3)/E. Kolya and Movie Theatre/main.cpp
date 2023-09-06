// ﷽
// https://codeforces.com/contest/1862/problem/E
// Codeforces -> Codeforces Round 894 (Div. 3) -> E. Kolya and Movie Theatre

#include <bits/stdc++.h>
#include <queue>
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
    int n, m, d;
    cin >> n >> m >> d;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    priority_queue<int> pq;
    int s = 0;
    for (int i = 0; i < n; i++) {
        while (pq.size() > m - 1 || pq.size() && pq.top() >= 0) {
            s -= -pq.top();
            pq.pop();
        }

        ans = max(ans, a[i] + s - d * (i + 1));

        s += a[i];
        pq.push(-a[i]);
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
