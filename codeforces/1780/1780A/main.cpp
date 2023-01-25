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
    int n; cin >> n; ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    bool one = false, zero = false;
    int o, z;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((a[i] + a[j]) % 2 == 0 && one) {
                cout << "YES" << endl;
                cout << i + 1 << " " << j + 1 << " " << o + 1 << endl;
                return;
            } 
            if ((a[i] + a[j]) % 2 == 1 && zero) {
                cout << "YES" << endl;
                cout << i + 1 << " " << j + 1 << " " << z + 1 << endl;
                return;
            }
        }
        if (a[i] & 1) one = true, o = i;
        else zero = true, z = i;
    }

    cout << "NO" << endl;
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
