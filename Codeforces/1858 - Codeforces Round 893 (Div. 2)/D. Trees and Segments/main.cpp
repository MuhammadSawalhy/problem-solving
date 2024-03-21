// ﷽
// https://codeforces.com/contest/1858/problem/D

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

vector<vector<int>> calcpref(const vector<int> &a) {
    // pref[i][j] = max len of a suffix at i of ones using atmost j operations
    int n = a.size();
    vector<vector<int>> pref(n + 2, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        pref[i][0] = a[i - 1] == 1 ? pref[i - 1][0] + 1 : 0;
        for (int j = 1; j <= n; j++) {
            maxit(pref[i][j], pref[i - 1][j - (a[i - 1] == 0)] + 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            maxit(pref[i][j], pref[i - 1][j]);
        }
    }

    return pref;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> a(n);
    vector<int> ones(n + 2);
    for (int i = 0; i < n; i++) a[i] = s[i] - '0', ones[i + 1] = ones[i] + a[i];

    auto pref = calcpref(a);
    reverse(all(a));
    auto suff = calcpref(a);
    reverse(all(suff));

    debug(a);
    for (auto x : suff) {
        debug(x);
    }

    vector<int> dp(n + 1, -1e9);
    for (int i = 0; i < n; i++) {
        for (int j = i; j <= n; j++) {
            int len = j - i;
            int x = ones[j] - ones[i];
            if (x > k) continue;
            maxit(dp[len], pref[i][k - x], suff[j + 1][k - x]);
        }
    }

    for (int j = 1; j <= n; j++) {
        int ans = 0;
        for (int len = 0; len <= n; len++) {
            maxit(ans, j * len + dp[len]);
        }
        cout << ans << ' ';
    }

    cout << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    // stress(argc, argv);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
