// ﷽
// https://codeforces.com/contest/1993/problem/E#

#include <bits/stdc++.h>
#include <ratio>
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
#define pii pair<int, int>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1, vector<int>(m + 1));

    for (int i = 0; i < n; i++) {
        int x = 0;
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            x ^= g[i][j];
        }
        g[i][m] = x;
    }

    for (int j = 0; j <= m; j++) {
        int x = 0;
        for (int i = 0; i < n; i++) {
            x ^= g[i][j];
        }
        g[n][j] = x;
    }

    n++, m++;

    const int inf = 1e9;

    debug(g);

    vector<vector<int>> dr(n, vector<int>(n));
    vector<vector<int>> dc(m, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                dr[i][j] += abs(g[i][k] - g[j][k]);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                dc[i][j] += abs(g[k][i] - g[k][j]);
            }
        }
    }

    int dpr[m][n][1 << n];
    memset(dpr, '?', sizeof dpr);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int mask = 0; mask < 1 << n; mask++) {
                dpr[j][i][mask] = inf;
            }
        }
    }

    for (int c = 0; c < m; c++) {
        for (int i = 0; i < n; i++) {
            dpr[c][i][1 << i] = 0;
        }
        for (int mask = 1; mask < 1 << n; mask++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int next = mask | (1 << j);
                    int delta = dr[i][j] - abs(g[i][c] - g[j][c]);
                    minit(dpr[c][j][next], dpr[c][i][mask] + delta);
                }
            }
        }
    }

    int dpc[n][m][1 << m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int mask = 0; mask < 1 << m; mask++) {
                dpc[i][j][mask] = inf;
            }
        }
    }

    for (int r = 0; r < n; r++) {
        for (int i = 0; i < m; i++) {
            dpc[r][i][1 << i] = 0;
        }
        for (int mask = 1; mask < 1 << m; mask++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    int next = mask | (1 << j);
                    int delta = dc[i][j] - abs(g[r][i] - g[r][j]);
                    minit(dpc[r][j][next], dpc[r][i][mask] + delta);
                }
            }
        }
    }

    int ans = inf;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            int R = inf, C = R;

            {
                // bitmask dp here to get min R
                int mask = ((1 << n) - 1) ^ (1 << r);
                for (int i = 0; i < n; i++) {
                    minit(R, dpr[c][i][mask]);
                }
            }

            {
                // bitmask dp here to get min R
                int mask = ((1 << m) - 1) ^ (1 << c);
                for (int i = 0; i < m; i++) {
                    minit(C, dpc[r][i][mask]);
                }
            }

            debug(r, c, R, C);
            minit(ans, R + C);
        }
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
