// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

int n, m;

void solve() {
    cin >> n >> m;
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    pair<ll, ll> c[4];
    c[0] = pair(1ll, 1ll);
    c[1] = pair(n, m);
    c[2] = pair(1ll, m);
    c[3] = pair(n, 1ll);

    for (int i = 0; i < 4; i++)
        if (pair(x, y) == c[i] || pair(a, b) == c[i]) {
            cout << 2 << '\n';
            return;
        }

    if (x == 1 || a == 1 || x == n || a == n || y == 1 || b == 1 || y == m || b == m) {
        cout << "3\n";
        return;
    }

    cout << "4\n";
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
