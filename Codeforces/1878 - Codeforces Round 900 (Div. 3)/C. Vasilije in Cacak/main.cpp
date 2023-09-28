// بسم الله الرحمن الرحيم
// https://codeforces.com/contest/1878/problem/C
// Codeforces -> Codeforces Round 900 (Div. 3) -> C. Vasilije in Cacak

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

long long sum(int a, int b) {
    a--;
    return b * (b + 1) / 2 - a * (a + 1) / 2;
}

void solve() {
    int n, k, x;
    cin >> n >> k >> x;

    // if > n - k + 1 ... n  -> no
    // if < 1 ... k  -> no
    if (x < sum(1, k) || x > sum(n - k + 1, n)) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
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
