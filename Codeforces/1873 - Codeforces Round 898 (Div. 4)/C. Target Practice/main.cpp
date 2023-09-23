// ﷽
// https://codeforces.com/contest/1873/problem/C
// Codeforces -> Codeforces Round 898 (Div. 4) -> C. Target Practice

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
    int n = 10;
    string s;
    int c = 0;
    int x[200], y[200];
    for (int i = 0; i < n; i++) {
        cin >> s;
        debug(s);
        for (int j = 0; j < n; j++) {
            if (s[j] == 'X') {
                x[c] = i, y[c] = j;
                c++;
            }
        }
    }

    int ans = 0;

    debug(c);
    for (int i = 0; i < c; i++) {
        int xx = abs(x[i] - 5);
        if (x[i] >= 5) xx++;
        int yy = abs(y[i] - 5);
        if (y[i] >= 5) yy++;
        int p = max(xx, yy);
        debug(i, xx, yy, p);
        ans += 5 - p + 1;
    }

    cout << ans << '\n';
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
