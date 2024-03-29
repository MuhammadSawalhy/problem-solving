// ﷽
// https://codeforces.com/contest/1900/problem/B

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

bool solve(int a, int b, int c) {
    if (b > c) swap(b, c);
    int d = c - b;
    if (d & 1) return false;
    a -= d / 2;
    c -= d / 2;
    b += d / 2;
    assert(c == b);
    a += c;
    return a > 0;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << solve(a, b, c) << ' ' << solve(b, c, a) << ' ' << solve(c, a, b) << endl;
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
