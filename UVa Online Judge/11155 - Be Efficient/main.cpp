// Date: 31-12-2022
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

void solve() {
    int a, b, c, m, n;
    cin >> a >> b >> c >> m >> n;

    ll ps[n];
    ps[0] = a;
    int x = a;
    for (int i = 1; i < n; i++) {
        x = ps[i] = ((x * b + c) % m) + 1;
        ps[i] += ps[i - 1];
    }

    int ans = 0;
    map<int, int> fr;
    fr[0] += 1;

    for (int i = 0; i < n; i++) {
        ans += fr[ps[i] % m];
        fr[ps[i] % m]++;
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}
