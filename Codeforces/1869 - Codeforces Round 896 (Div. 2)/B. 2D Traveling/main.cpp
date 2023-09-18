// ﷽
// https://codeforces.com/contest/1869/problem/B
// Codeforces -> Codeforces Round 896 (Div. 2) -> B. 2D Traveling

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
    int n, k, a, b;
    cin >> n >> k >> a >> b;

    int x[n + 1], y[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    int ans = abs(x[a] - x[b]) + abs(y[a] - y[b]);

    int A = a <= k ? 0 : 1e18, B = b <= k ? 0 : 1e18;

    for (int i = 1; i <= k; i++) {
        A = min(A, abs(x[a] - x[i]) + abs(y[a] - y[i]));
    }

    for (int i = 1; i <= k; i++) {
        B = min(B, abs(x[b] - x[i]) + abs(y[b] - y[i]));
    }

    cout << min(A + B, ans) << endl;
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
