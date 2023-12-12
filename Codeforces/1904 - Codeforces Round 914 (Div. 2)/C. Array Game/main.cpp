// ﷽
// https://codeforces.com/contest/1904/problem/C

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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a));
    int mn = a[0];

    if (k >= 3) {
        cout << 0 << endl;
        return;
    }

    if (k == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                minit(mn, abs(a[i] - a[j]));
            }
        }

        cout << mn << endl;
        return;
    }


    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x = abs(a[i] - a[j]);
            minit(mn, x);
            auto it = lower_bound(all(a), x);
            if (it != a.end()) {
                minit(mn, *it - x);
            }
            if (it != a.begin()) {
                minit(mn, x - *(prev(it)));
            }
        }
    }

    cout << mn << endl;
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
