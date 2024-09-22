// ﷽
// https://codeforces.com/contest/2009/problem/D

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
    int n;
    cin >> n;
    bool p[n + 1][2];
    memset(p, 0, sizeof p);

    for (int i = 0, x, y; i < n;i ++) {
        cin >> x >> y;
        p[x][y] = 1;
    }

    debug(n);
    int ans = 0;
    for (int i = 0, cnt = 0, cnt2= 0; i <= n;i++) {
        ans += (p[i][0] + p[i][1]) * cnt;
        ans += (p[i][0] && p[i][1]) * cnt2;
        cnt += p[i][0] && p[i][1];
        cnt2 += p[i][0] + p[i][1];
        debug(i, cnt, cnt2);
    }

    for (int i = 1; i < n;i++) {
        ans += p[i][0] * p[i - 1][1] * p[i + 1][1];
    }

    for (int i = 1; i < n;i++) {
        ans += p[i][1] * p[i - 1][0] * p[i + 1][0];
    }

    cout << ans << endl;
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
