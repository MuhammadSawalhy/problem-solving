// ﷽
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <assert.h>

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

ll dp[1000][1000];
int t[1000];
int n, l, c;
int lec;

ll solve(int i, int j) {
    if (i >= lec && j >= n) return 0;
    if (i >= lec) return 1e18;
    ll &r = dp[i][j];
    if (r != -1) return r;
    r = 1e18;

    int s = 0;
    for (int k = j; k < n; k++) {
        s += t[k];
        if (s > l) break;
        if (l - s > 10) {
            r = min(r, (l - s - 10) * (l - s - 10) + solve(i + 1, k + 1));
        } else if (l - s == 0) {
            r = min(r, solve(i + 1, k + 1));
        } else {
            r = min(r, -c + solve(i + 1, k + 1));
        }
    }

    return r;
}

void solve() {
    cin >> l >> c;

    lec = 1;
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        s += t[i];
        if (s > l) {
            s = t[i];
            lec++;
        }
    }

    assert(lec <= n);

    for (int i = 0; i < lec; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;

    solve(0, 0);

    cout << "Minimum number of lectures: " << lec << endl;
    cout << "Total dissatisfaction index: " << dp[0][0] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    bool first = true;
    while (cin >> n, n) {
        if (!first)
            cout << endl;
        first = false;
        cout << "Case " << t++ << ":" << endl;
        solve();
    }

    return 0;
}
