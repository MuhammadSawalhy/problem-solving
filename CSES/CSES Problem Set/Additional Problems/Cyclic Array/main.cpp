// ﷽
// https://cses.fi/problemset/task/1191

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
#define vvi vector<vector<int>>
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

    constexpr int lg = 20;
    int cnt[n][lg];

    for (int i = 0, icnt = 0, s = 0; i < n; i++) {
        while (icnt <= n && s <= k) {
            s += a[(i + icnt) % n];
            icnt++;
        }

        s -= a[(i + --icnt) % n];
        cnt[i][0] = icnt;
        debug(i, icnt, s);
        s -= a[i], --icnt;
    }

    for (int l = 1; l < lg; l++) {
        for (int i = 0; i < n; i++) {
            cnt[i][l] = cnt[i][l - 1] + cnt[(i + cnt[i][l - 1]) % n][l - 1];
        }
    }

    int ans = n;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        int icnt = 0;

        for (int l = lg - 1; ~l; l--) {
            if (icnt + cnt[(i + icnt) % n][l] < n) {
                cur += 1 << l;
                icnt += cnt[(i + icnt) % n][l];
            }
        }

        minit(ans, cur + 1);
    }

    cout << ans << '\n';
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
