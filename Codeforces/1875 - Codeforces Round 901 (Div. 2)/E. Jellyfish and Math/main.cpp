// ﷽
// https://codeforces.com/contest/1875/problem/E

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
    int a, b, c, d, m;
    cin >> a >> b >> c >> d >> m;
    debug(a, b, c, d, m);
    debug_bits(a);
    debug_bits(c);
    debug_bits(b);
    debug_bits(d);
    debug_bits(m);
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
