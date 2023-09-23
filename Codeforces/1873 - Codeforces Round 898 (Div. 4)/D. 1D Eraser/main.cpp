// ﷽
// https://codeforces.com/contest/1873/problem/D
// Codeforces -> Codeforces Round 898 (Div. 4) -> D. 1D Eraser

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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int i = 0;
    while (i < n && s[i] == 'W') i++;

    int ans = 0;

    while (i < n) {
        ans++;
        i += k;
        while (i < n && s[i] == 'W') i++;
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
