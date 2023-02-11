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
    int a[n];
    int all2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        all2 += a[i] == 2;
    }

    int twos = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == 2) twos++, all2--;
        if (twos == all2) {
            cout << i + 1 << endl;
            return;
        }
    }

    cout << -1 << endl;
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
