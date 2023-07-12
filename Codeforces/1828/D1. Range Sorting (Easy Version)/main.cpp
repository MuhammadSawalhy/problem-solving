// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

const int N = 5e3 + 1;
long long dp[N][N];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // vector<int> order(n);
    // vector<int> ind(n);
    // iota(all(order), 0);
    // sort(all(order), [&](int l, int r) { return a[l] < a[r]; });
    // for (int i = 0; i < n; i++)
    //     ind[order[i]] = i;

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         dp[i][j] = 0;
    //     }
    // }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int last = i;
        int mn = a[i];
        int y = 1e18;
        for (int j = i - 1; ~j; j--) {
            // keep last one that is greater than a[i]
            if (a[j] > mn) {
                last = j;
                dp[i][j] = (i - last);
                // update mn
                mn = min(mn, y);
            } else {
                dp[i][j] = dp[last - 1][j] + (i - last);
            }
            y = min(y, a[j]);
            ans += dp[i][j];
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
