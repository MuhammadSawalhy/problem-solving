// ﷽
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
    int n; cin >> n; ll a[n];
    int p[n + 1]; p[0] = 0;
    for (int i = 0; i < n; i++) cin >> a[i], p[i + 1] = p[i] + a[i];

    int s = 0, e = n;
    while (e - s > 1) {
        int mid = (s + e) / 2;
        cout << "? " << mid << " ";
        for (int i = 1; i <= mid; i++) {
            cout << i << " ";
        }
        cout << endl;
        ll ans = 0;
        cin >> ans;
        if (ans == p[mid]) {
            s = mid;
        } else {
            e = mid;
        }
    }

    cout << "! " << e << endl;
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
