// ﷽
// https://codeforces.com/contest/1993/problem/D

#include <algorithm>
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
#define pii pair<int, int>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int rest = n - (n - 1) / k * k;

    debug(n, k, rest);
    debug(a);

    int l = 0, r = 1e9 + 1;
    vector<int> dp(n);

    const int inf = 1e18;

    while (r - l > 1) {
        int x = (l + r) / 2;
        // count items >= x such that
        // the count is > rest / 2

        dp.assign(n, -inf);

        for (int i = n - 1; i >= 0; i--) {
            if (i % k == rest - 1) {
                maxit(dp[i], i + k < n ? dp[i + k] : -inf, 1ll * (a[i] >= x));
            } else {
                maxit(dp[i], i + k < n ? dp[i + k] : -inf, dp[i + 1] + (a[i] >= x));
            }
        }

        if (dp[0] > rest / 2) {
            l = x;
        } else {
            r = x;
        }
    }

    cout << l << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
