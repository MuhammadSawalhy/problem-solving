// ﷽
// https://codeforces.com/contest/1900/problem/A

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
    s = '#' + s + '#';
    int last = 0;
    n += 2;

    bool gt2 = false;
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == '#') {
            sum += i - last - 1;
            if (i - last - 1  > 2) gt2 = true;
            last = i;
        }
    }

    if (gt2) cout << 2 << endl;
    else cout << sum << endl;
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
