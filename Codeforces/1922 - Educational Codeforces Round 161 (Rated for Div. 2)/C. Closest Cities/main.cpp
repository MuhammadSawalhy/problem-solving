// ﷽
// https://codeforces.com/contest/1922/problem/C

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
    cin >> n;
    vector<int> a(n + 2);
    a[0] = -1e18;
    a[n + 1] = 1e18;
    vector<int> psum(n + 1), ssum(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 2; i <= n; i++) {
        // go right (i - 1 -> i)
        if (a[i] - a[i - 1] < a[i - 1] - a[i - 2])
            psum[i] = psum[i - 1] + 1;
        else
            psum[i] = psum[i - 1] + (a[i] - a[i - 1]);
    }

    for (int i = n - 1; i >= 1; i--) {
        // go left (i + 1 -> i)
        if (a[i + 1] - a[i] < a[i + 2] - a[i + 1])
            ssum[i] = ssum[i + 1] + 1;
        else
            ssum[i] = ssum[i + 1] + (a[i + 1] - a[i]);
    }


    cin >> m;
    while (m--) {
        int i, j;
        cin >> i >> j;

        if (i < j) {
            cout << psum[j] - psum[i] << endl;
        } else {
            cout << ssum[j] - ssum[i] << endl;
        }
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
