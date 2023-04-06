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

void solve() {
    int n, m;
    cin >> n >> m;

    ll ans = 0;
    int cards[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> cards[i][j];
    }

    for (int j = 0; j < m; j++) {
        vector<int> x;
        for (int i = 0; i < n; i++) {
            x.push_back(cards[i][j]);
        }
        sort(x.rbegin(), x.rend());

        ll s = 0;
        for (int i = 0; i < n; i++) {
            ans += s - 1LL * x[i] * (i);
            s += x[i];
        }
    }

    cout << ans << '\n';
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
