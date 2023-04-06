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
    int q;
    cin >> q;

    ll l = 1, r = 9e18;

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll a, b, n;
            cin >> a >> b >> n;
            ll L, R;
            if (n > 1) {
                L = (a - b) * (n - 2) + a + 1, R = (a - b) * (n - 1) + a;
            } else {
                L = 1, R = a;
            }
            if (max(l, L) <= min(r, R)) {
                l = max(l, L);
                r = min(r, R);
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        } else {
            ll a, b;
            cin >> a >> b;

            int x = 0;
            while (x * (a - b) + a < l) x++;

            if (x * (a - b) + a >= r) {
                cout << x + 1 << ' '; 
            } else {
                cout << "-1 ";
            }
        }
    }

    cout << '\n';
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

