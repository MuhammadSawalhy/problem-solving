#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define maxit(x, v...) x = max({x, v})
#define minit(x, v...) x = min({x, v})

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif


const int N = 2e5 + 5;
int dp[N][2];

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int a[n];

    for (int i = 0, j = 0; i < n; i++) {
        a[i] = s[i] == 'P';
        if (a[i] == 0) {
            j++;
        }
    }

    int prev = 0;
    int m = 0;
    int cnt[n + 2], ind[n + 2];
    for (int i = 0, j; i < n; i = j) {
        j = i;
        while (j < n && a[j] == a[i]) j++;
        if (a[i] == 0 && i == 0) {
            prev = j - i;
            continue;
        }
        ind[++m] = i;
        cnt[m] = (j - i);
    }

    if (a[n - 1] == 1) m--;

    for (int i = 0; i <= m; i++) {
        dp[i][0] = dp[i][1] = 1e9;
    }

    assert(m & 1 ^ 1);

    dp[0][0] = 0;
    dp[0][1] = 0;

    debug_itr(cnt + 1, m);
    debug_itr(ind + 1, m);
    for (int i = 1; i <= m; i++) {
        if (cnt[i] & 1) {

        } else {

        }

        for (int j = 0; j < 2; j++) {
            // propagate zero
            int c = cnt[i] + j;
            int cost0 = (ind[i] - prev);
            // i + i + 1 + i + 2 + ... - prev - prev - 1 - prev - 2 - ...
            if (c & 1) {
                minit(dp[i][j], dp[i - 2][1] + (c - 1) / 2 * cost0 + (cnt[i - 1] + 1) / 2);
                // 1 0 1 1
                if (i > 2 && cnt[i - 2] % 2 == 0 && cnt[i - 3] % 2 == cnt[i - 1] % 2) {
                    int cost_ = cnt[i - 2] * (ind[i - 2] - (prev - cnt[i - 2]));
                    minit(dp[i][j], dp[i - 4][0] + cost_ / 2 + (c - 1) / 2 * cost0 + (cnt[i - 1] + cnt[i - 3] + 1) / 2);
                }
            } else {
                minit(dp[i][j], dp[i - 2][0] + c / 2 * cost0);
            }
            debug(i, j, dp[i][j]);
        }
        prev += cnt[i];
    }

    cout << dp[m][0] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
