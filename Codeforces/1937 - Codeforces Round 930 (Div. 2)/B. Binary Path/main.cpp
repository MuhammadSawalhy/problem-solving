// ﷽
// https://codeforces.com/contest/1937/problem/B

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
    string s;
    cin >> s;
    string t;
    cin >> t;

    int down = 0;
    while (down < n - 1) {
        if (s[down + 1] <= t[down]) {
            down++;
        } else {
            break;
        }
    }

    int i = down;
    while (i > 0) {
        if (s[i] == t[i - 1]) {
            i--;
        } else {
            break;
        }
    }
    debug(down, i);

    string ans;

    for (int i = 0; i <= down; i++) {
        ans += s[i];
    }
    for (int i = down; i < n; i++) {
        ans += t[i];
    }

    cout << ans << endl;
    cout << down - i + 1 << endl;
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
