// ﷽
// https://codeforces.com/contest/1899/problem/D

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

bool is_power2(int x) {
    return x > 0 && (x & (x - 1)) == 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<pair<int, int>, int> fr;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x = 0;
        int y = a[i];
        while (y % 2 == 0) {
            x++;
            y /= 2;
        }

        ans += fr[{a[i] - x, y}];
        fr[{a[i] - x, y}]++;
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
