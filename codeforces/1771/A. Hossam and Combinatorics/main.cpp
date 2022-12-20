// Date: 11-12-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef LOCAL
#include "debug.hpp"
#endif

void solve() {
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll d = *max_element(a, a + n) - *min_element(a, a + n);

    if (d == 0) {
        cout << (ll) n * (n - 1) << endl;
        return;
    }

    map<ll, int> fr;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += fr[a[i] - d] + fr[a[i] + d];

        fr[a[i]]++;
    }

    cout << ans * 2 << endl;
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
