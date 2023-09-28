// بسم الله الرحمن الرحيم
// https://codeforces.com/contest/1878/problem/B
// Codeforces -> Codeforces Round 900 (Div. 3) -> B. Aleksa and Stack

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
    int n;
    cin >> n;

    int i = 0;

    int a[n];
    a[i++] = 2;
    a[i++] = 3;

    while (i < n) {
        int cur = a[i - 1] + 1;
        while ((3 * cur) % (a[i - 1] + a[i - 2]) == 0) cur++;
        a[i++] = cur;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
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
