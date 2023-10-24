// ﷽
// https://codeforces.com/contest/1875/problem/C

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
    int n, m;
    cin >> n >> m;
    n %= m;

    int cnt = 0;
    int M = m;
    while (M % 2 == 0) M >>= 1;

    if (n % M != 0) {
        cout << -1 << endl;
        return;
    }

    int ops = 0;
    while (n && ops < 2000) {
        ops++;
        cnt += n;
        n *= 2;
        n %= m;
    }

    if (n) {
        cout << -1 << endl;
    } else {
        cout << cnt << endl;
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
