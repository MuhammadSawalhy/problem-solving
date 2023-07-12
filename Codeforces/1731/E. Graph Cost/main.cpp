// Date: 27-12-2022
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);

    for (int i = n; i > 0; i--) {
        a[i] = (ll)(n / i) * (n / i - 1) / 2;
        for (int j = i + i; j <= n; j+=i)
            a[i] -= a[j];
    }

    ll cost = m;
    for (int g = n; g > 1; g--) {
        // Bg (g - 1) <= Ag
        ll b = min(a[g], (ll)m) / (g - 1);
        cost += b;
        m -= b * (g - 1);
    }

    if (m != 0)
        cout << -1 << endl;
    else
        cout << cost << endl;
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
