// ﷽
// https://codeforces.com/contest/1869/problem/A
// Codeforces -> Codeforces Round 896 (Div. 2) -> A. Make It Zero

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

void solve() {
    int n;
    cin >> n;
    int x = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        x ^= a[i];
    }

    if (n & 1) {
        cout << 4 << endl;
        cout << 1 << ' ' << 2 << endl;
        cout << 1 << ' ' << 2 << endl;
        cout << 2 << ' ' << n << endl;
        cout << 2 << ' ' << n << endl;
        return;
    }

    cout << 2 << endl;
    cout << 1 << ' ' << n << endl;
    cout << 1 << ' ' << n << endl;
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
