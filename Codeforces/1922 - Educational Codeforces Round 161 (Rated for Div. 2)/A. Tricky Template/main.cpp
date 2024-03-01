// ﷽
// https://codeforces.com/contest/1922/problem/A

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
    string a, b, c;
    cin >> a >> b >>c;

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if (c[i] != b[i]) {
                cout << "YES\n";
                return;
            }
        } else {
            if (c[i] != a[i] && c[i] != b[i]) {
                cout << "YES\n";
                return;
            }
        }
    }


    cout << "NO\n";
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
