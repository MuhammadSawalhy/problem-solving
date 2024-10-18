// ﷽
// https://cses.fi/problemset/task/2088

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
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vii vector<pii>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 3003;
int a[N];
int ps[N];
int dp[N][N];

int C(int l, int r) {
    int s = ps[r + 1] - ps[l];
    return s * s;
}

void go(int k, int l, int r, int optl, int optr) {
    if (l > r) return;
    int mid = (l + r) / 2;

    pii mn = {1e18, -1};
    for (int i = optl; i <= min(mid, optr); i++) {
        minit(mn, {dp[k - 1][i - 1] + C(i, mid), i});
    }

    dp[k][mid] = mn.first;
    int opt = mn.second;

    go(k, l, mid - 1, optl, opt);
    go(k, mid + 1, r, opt, optr);
}

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0, s = 0; i < n; i++) {
        cin >> a[i];
        ps[i + 1] = ps[i] + a[i];
        dp[0][i] = ps[i + 1] * ps[i + 1];
    }

    for (int i = 1; i < k; i++) {
        go(i, 0, n - 1, 0, n - 1);
    }

    cout << dp[k - 1][n - 1] << '\n';
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}

