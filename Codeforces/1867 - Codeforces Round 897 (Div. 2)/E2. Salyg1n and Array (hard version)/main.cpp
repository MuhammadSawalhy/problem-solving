// ﷽
// https://codeforces.com/contest/1867/problem/E2

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

void ask(int x) {
    cout << "? " << x << endl;
}

void solve() {
    int n, k;
    cin >> n >> k;

    int ans = 0, x;

    while (n > 2 * k) {
        n -= k;
        ask(n + 1);
        cin >> x;
        ans ^= x;
    }

    ask(n - k + 1);
    cin >> x;
    ans ^= x;
    ask(n - k - (n - k) / 2 + 1);
    cin >> x;
    ans ^= x;

    ask(1);
    cin >> x;
    ans ^= x;

    cout << "! " << ans << endl;
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
