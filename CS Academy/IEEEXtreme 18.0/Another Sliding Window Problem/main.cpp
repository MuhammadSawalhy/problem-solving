// ﷽
// https://csacademy.com/ieeextreme18/task/another-sliding-window-problem/

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

constexpr int32_t N = 1e4;
int32_t dp[N][N];

void solve() {
    int n, q;
    cin >> n >> q;

    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (q--) {
        int x;
        cin >> x;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                int mx = a[i];
                int l = i - j + 1;
                int ii = i, jj = j;
                ii -= l & 1;
                for (int l = jj, r = ii; l < r; l++, r--) {
                    maxit(mx, a[l] + a[r]);
                }

                if (mx <= x) {
                    ans += a[i] - a[j];
                }
            }
        }

        cout << ans << '\n';
    }
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
