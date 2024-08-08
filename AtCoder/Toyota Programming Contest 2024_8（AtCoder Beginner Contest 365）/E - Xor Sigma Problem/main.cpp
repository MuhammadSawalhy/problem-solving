// ﷽
// https://atcoder.jp/contests/abc365/tasks/abc365_e

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

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> cnt(n, vector<int>(30));

    for (int j = 0; j < 30; j++) {
        cnt[n - 1][j] = (a[n - 1] >> j) & 1;
    }

    int ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        int cur = 0;
        debug(i, a[i]);
        for (int j = 0; j < 30; j++) {
            int x = cnt[i + 1][j];
            int y = n - i - 1 - x;
            debug(j, x, y);
            if (a[i] >> j & 1) {
                cur += (1ll << j) * y;
            } else {
                cur += (1ll << j) * x;
            }
        }

        ans += cur;
        debug(cur);

        for (int j = 0; j < 30; j++) {
            if ((a[i] >> j & 1)) {
                cnt[i][j] = n - i - 1 - cnt[i + 1][j];
                cnt[i][j]++;
            } else {
                cnt[i][j] = cnt[i + 1][j];
            }
        }
    }


    cout << ans << endl;
    return 0;
}
