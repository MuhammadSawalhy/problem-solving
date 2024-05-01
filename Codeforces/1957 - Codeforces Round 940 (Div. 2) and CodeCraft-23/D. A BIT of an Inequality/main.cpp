// ﷽
// https://codeforces.com/contest/1957/problem/D

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 1e5 + 5;
int pref[N][30][2], suff[N][30][2];

void solve() {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int j = 0; j < 30; j++) {
        for (int k = 0; k < 2; k++) {
            suff[n + 1][j][k] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 30; j++) {
            pref[i][j][0] = pref[i - 1][j][0];
            pref[i][j][1] = pref[i - 1][j][1];
            if (a[i] >> j & 1) {
                swap(pref[i][j][0], pref[i][j][1]);
                pref[i][j][1]++;
            } else {
                pref[i][j][0]++;
            }
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < 30; j++) {
            suff[i][j][0] = suff[i + 1][j][0];
            suff[i][j][1] = suff[i + 1][j][1];
            if (a[i] >> j & 1) {
                swap(suff[i][j][0], suff[i][j][1]);
                suff[i][j][1]++;
            } else {
                suff[i][j][0]++;
            }
        }
    }

    debug(n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int msb = 63 - __builtin_clzll(a[i]);
        debug(i, a[i], msb);
        debug(pref[i][msb][0], suff[i][msb][1]);
        debug(pref[i][msb][1], suff[i][msb][0]);
        ans += pref[i][msb][0] * suff[i][msb][1];
        ans += pref[i][msb][1] * suff[i][msb][0];
        debug(ans);
    }

    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
