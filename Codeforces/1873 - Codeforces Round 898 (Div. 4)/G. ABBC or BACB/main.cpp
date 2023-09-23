// ﷽
// https://codeforces.com/contest/1873/problem/G
// Codeforces -> Codeforces Round 898 (Div. 4) -> G. ABBC or BACB

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
    string s;
    cin >> s;
    int n = s.length();

    int i = 0, j, ans = 0;
    debug(s);
    while (i < n) {
        int cur = 0;
        int a = 0;
        int mn = 1e9;

        j = i;
        while (j < n && s[j] != 'C') {
            cur += s[j] == 'A';
            if (s[j] != 'A') {
                mn = min(mn, cur);
                a += cur;
                cur = 0;
            }
            j++;
        }

        mn = min(mn, cur);
        a += cur;
        cur = 0;

        debug(i, j, a, mn);

        ans += a - mn;
        i = j + 1;
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
