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
    int s = 0;
    for (int i = 0; i < n; i++) cin >> a[i], s += a[i];

    bool ok = false, ok2 = false;;
    for (int i = 1; i < n; i++)
        ok |= a[i] == -1 && a[i - 1] == -1, ok2 |= a[i] != a[i - 1];


    if (ok) {
        cout << s + 4 << endl;
    } else if (ok2) {
        cout << s << endl;
    } else {
        cout << s - 4 << endl;
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
