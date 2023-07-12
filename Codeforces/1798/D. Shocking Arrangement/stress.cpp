// Date: 11-12-2022
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

void solve() {
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    long long val = a[n - 1] - a[0];

    do {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                long long s = 0;
                for (int k = i; k <= j; k++) {
                    s += a[k];
                }
                ok &= s < val;
            }
        }
        if (ok) {
            // debug_itr(a, a + n);
            return cout << "YES" << endl, void();
        }
    } while (next_permutation(a, a + n));
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
