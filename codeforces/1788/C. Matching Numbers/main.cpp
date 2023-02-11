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

    if (n % 2 == 0) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    int x = n * 2;

    for (int i = 1; i <= n; i += 2) {
        cout << i << " " << x-- << endl;
    }

    for (int i = 2; i <= n; i += 2) {
        cout << i << " " << x-- << endl;
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
