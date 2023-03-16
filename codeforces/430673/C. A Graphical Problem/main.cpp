// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

void solve() {
    int n;
    cin >> n;
    int h[n];

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }


    sort(h, h + n);

    ll mn = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        if (i)
            mn += h[i] - h[i - 1];
        mx += max(h[n - 1] - h[i], h[i] - h[0]);
    }

    cout << mn << " " << mx - (h[n - 1] - h[0]) << endl;
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
