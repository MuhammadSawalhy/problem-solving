// ﷽
// https://codeforces.com/contest/2003/problem/E1

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

const int N = 5e3 + 3;

int dp[N][N];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = -1e18;
        }
    }

    int l[m], r[m];
    for (int i = 0; i < m; i++) cin >> l[i] >> r[i], l[i]--, r[i]--;

    dp[0][0] = 0;
    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k < m && r[k] < i) k++;
        if (k < m && l[k] == i) {
            for (int h = 1; h < r[k] - l[k] + 1; h++) {
                int hh = r[k] - l[k] + 1 - h;
                for (int j = 0; j <= i; j++) {
                    maxit(dp[r[k] + 1][j + hh], dp[i][j] + j * h);
                }
            }
            i = r[k];
        } else {
            for (int j = 0; j <= i; j++) {
                // put 1
                maxit(dp[i + 1][j + 1], dp[i][j]);
                // put 0
                maxit(dp[i + 1][j], dp[i][j] + j);
            }
        }
    }


    int ans = 0;
    debug(n, m);
    for (int j = 0; j <= n; j++) {
        int x = j, y = n - j;
        int z = dp[n][j];
        maxit(ans, x * (x - 1) / 2 + y * (y - 1) / 2 + z);
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

