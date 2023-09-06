// ﷽
// https://codeforces.com/contest/1864/problem/D
// Codeforces -> Harbour.Space Scholarship Contest 2023-2024 (Div. 1 + Div. 2) -> D. Matrix Cascade

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
    int n;
    cin >> n;

    int a[n][n];
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
            a[i][j] = s[j] - '0';
    }

    vector<int> diag(3 * n), rdiag(3 * n);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int cur = 0;
        vector<int> newdiag = diag, rnewdiag = rdiag;

        for (int k = 0; k <= i + 0; k++)
            cur ^= diag[k];

        debug(diag);
        debug(rdiag);
        debug(i, cur);

        for (int j = 0; j < n; j++) {
            debug(i, j, cur, a[i][j]);

            if (cur ^ a[i][j]) {
                ans++;

                newdiag[i + j] ^= 1;
                rnewdiag[i - j + n] ^= 1;
            }

            cur ^= diag[i + j + 1];  // add
            cur ^= rdiag[i - j + n]; // remove
        }

        diag = newdiag, rdiag = rnewdiag;
    }

    cout << ans << endl;
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
