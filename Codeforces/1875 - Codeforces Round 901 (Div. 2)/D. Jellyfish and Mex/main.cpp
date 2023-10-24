// ﷽
// https://codeforces.com/contest/1875/problem/D#

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
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

vector<int> fr(5005);
vector<int> dp(5005);

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i <= n + 1; i++) {
        dp[i] = 1e18;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a));
    if (a[0] != 0) {
        cout << 0 << endl;
        return;
    }

    int N = 1;
    while (N < n && a[N] - a[N - 1] <= 1) N++;

    for (int i = 0; i < N; i++) {
        fr[a[i]]++;
    }

    n = a[N - 1];

    dp[n + 1] = 0;

    for (int i = n; i >= 0; i--) {
        for (int mex = i + 1; mex <= n + 1; mex++) {
            minit(dp[i], dp[mex] + (fr[i] - 1) * mex + i);
        }
    }

    cout << dp[0] << endl;

    for (int i = 0; i <= n; i++) {
        fr[i] = 0;
    }
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
