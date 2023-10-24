// ﷽
// https://codeforces.com/contest/1875/problem/0

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
    int a, b, n;
    cin >> a >> b >> n;
    int ans = b - 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans += min(a, x + 1) - 1;
    }

    cout << ans + 1 << endl;
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
