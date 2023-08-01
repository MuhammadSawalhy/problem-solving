// ﷽
// 12 جُمادى الآخرة 1444
// Jan 04, 2023
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    ll ps[n + 1];
    ps[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> ps[i];
        ps[i] += ps[i - 1];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << ps[r] - ps[l - 1] << endl;
    }

    return 0;
}
