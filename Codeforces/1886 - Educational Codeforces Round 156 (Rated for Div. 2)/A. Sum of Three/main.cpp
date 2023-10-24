// ﷽
// https://codeforces.com/contest/1886/problem/0

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

    if (n <= 6 || n == 9) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    if (n % 3 == 0) {
        cout << "1 4 " << n - 5 << "\n";
    } else {
        cout << "1 2 " << n - 3 << '\n';
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
