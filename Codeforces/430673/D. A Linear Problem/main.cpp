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
    ll x[n], y[n];

    bool ok = true;
    map<pair<int, int>, int> fr;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        if (x[i] == 0 && y[i] == 0) {
            ok = false;
        }

        if (!ok) continue;

        int g = gcd(x[i], y[i]);
        pair<int, int> key = {x[i] / g, y[i] / g};
        fr[key]++;
    }

    if (!ok)
        cout << 1 << endl;
    else
        cout << fr.size() << endl;
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
