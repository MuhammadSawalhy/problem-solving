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

const int N = 1e5 + 5;
int sz[3];
int c[3][N];

ll sq(ll x) {
    return x * x;
}

ll solve(int i, int j, int k) {
    ll ans = 9e18;
    for (int r = 0; r < sz[i]; r++) {
        int w = lower_bound(c[j], c[j] + sz[j], c[i][r]) - c[j];
        if (w == sz[j]) continue;
        int e = upper_bound(c[k], c[k] + sz[k], c[i][r]) - c[k];
        if (e == 0) continue;
        e--;
        ans = min(ans, sq(c[i][r] - c[j][w]) + sq(c[i][r] - c[k][e]) + sq(c[j][w] - c[k][e]));
    }
    return ans;
}

void solve() {
    for (int j = 0; j < 3; j++)
        cin >> sz[j], debug(sz[j]);
    for (int j = 0; j < 3; j++)
        for (int i = 0; i < sz[j]; i++)
            cin >> c[j][i];
    for (int j = 0; j < 3; j++)
        sort(c[j], c[j] + sz[j]);

    ll ans = 9e18;
    ans = min(ans, solve(0, 1, 2));
    ans = min(ans, solve(0, 2, 1));
    ans = min(ans, solve(1, 0, 2));
    ans = min(ans, solve(1, 2, 0));
    ans = min(ans, solve(2, 0, 1));
    ans = min(ans, solve(2, 1, 0));

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
