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

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << 1;
    bool breaked = false;
    int last = a[0];

    for (int i = 1; i < n; i++) {
        if (!breaked && a[i] >= last || breaked && a[i] <= a[0] && a[i] >= last) {
            cout << 1;
            last = a[i];
        } else if (!breaked && a[i] <= a[0]) {
            cout << 1;
            last = a[i];
            breaked = true;
        } else {
            cout << 0;
        }
    }

    cout << endl;
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
