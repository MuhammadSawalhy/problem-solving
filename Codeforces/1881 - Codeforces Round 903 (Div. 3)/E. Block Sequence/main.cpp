// ﷽
// https://codeforces.com/contest/1881/problem/E

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

const int N = 2e5 + 5;
vector<int> dp(N);
vector<int> a(N);
int n;

int calc(int i) {
    if (i == n) {
        return 0;
    }
    if (i > n) {
        return n;
    }

    if (dp[i] != -1) {
        return dp[i];
    }

    return dp[i] = min(calc(i + 1) + 1, calc(i + a[i] + 1));
}

void solve() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        dp[i] = -1;
        cin >> a[i];
    }

    cout << calc(0) << endl;
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
