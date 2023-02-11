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
    int n, c;
    cin >> n >> c;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i], a[i] += i + 1;

    sort(a, a + n);

    int i = 0;
    while (i < n && c >= a[i]) {
        c -= a[i++];
    }
    cout << i << endl;
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
