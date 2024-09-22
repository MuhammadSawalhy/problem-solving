// ﷽
// https://codeforces.com/contest/2014/problem/D

#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, d, k;
    cin >> n >> d >> k;

    vi ps(n + 5);

    vector<pii> points;
    vector<int> out(n + 2);
    vector<int> in(n + 2);
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        in[l]++;
        out[r + 1]++;
    }


    int ans1 = -1, ans2 = -1;

    int cnt = 0;
    int mn = 1e9;
    int mx = 0;

    for (int i = 1; i < d; i++) {
        cnt += in[i];
    }

    debug(n);
    for (int i = 1; i <= n - d + 1; i++) {
        if (i + d - 1 <= n)
            cnt += in[i + d - 1];
        cnt -= out[i];
        debug(i , cnt);

        minit(mn, cnt);
        maxit(mx, cnt);
    }

    debug(mn, mx);

    cnt = 0;
    for (int i = 1; i < d; i++) {
        cnt += in[i];
    }


    for (int i = 1; i <= n - d + 1; i++) {
        if (i + d - 1 <= n)
            cnt += in[i + d - 1];
        cnt -= out[i];
        debug(i , cnt);

        if (cnt == mn && ans1 == -1) ans1 = i;
        if (cnt == mx && ans2 == -1) ans2 = i;
    }

    cout << ans2 << " " << ans1 << endl;
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
