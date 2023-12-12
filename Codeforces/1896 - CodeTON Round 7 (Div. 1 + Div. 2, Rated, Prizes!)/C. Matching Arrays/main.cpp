// ﷽
// https://codeforces.com/contest/1896/problem/C

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
    int n, x;
    cin >> n >> x;
    pair<int, int> a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }

    sort(a, a + n);
    sort(b, b + n);
    int ans = 0;
    rotate(b, b + x, b + n);
    debug_itr(b, n);
    for (int i = 0; i < n; i++) {
        ans += a[i].first > b[i].first;
    }

    cout << (ans == x ? "YES" : "NO") << "\n";
    if (ans == x) {
        int B[n];
        for (int i = 0; i < n; i++) {
            B[a[i].second] = b[i].first;
        }
        for (int i = 0; i < n; i++) {
            cout << B[i] << " \n"[i == n - 1];
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
