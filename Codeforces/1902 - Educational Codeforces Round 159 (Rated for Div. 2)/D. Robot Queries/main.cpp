// ﷽
// https://codeforces.com/contest/1902/problem/D

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

void solve() {
    int n, q;
    string s;
    cin >> n >> q;
    cin >> s;

    int dx[n + 1], dy[n + 1];
    int rdx[n + 2], rdy[n + 2];
    memset(dx, 0, sizeof dx);
    memset(dy, 0, sizeof dy);
    memset(rdx, 0, sizeof rdx);
    memset(rdy, 0, sizeof rdy);

    for (int i = 0; i < n; i++) {
        dx[i + 1] = dx[i] + (s[i] == 'L' ? -1 : s[i] == 'R' ? +1
                                                            : 0);
        dy[i + 1] = dy[i] + (s[i] == 'D' ? -1 : s[i] == 'U' ? +1
                                                            : 0);
    }

    for (int i = n - 1; i >= 0; i--) {
        rdx[i + 1] = rdx[i + 2] + (s[i] == 'L' ? -1 : s[i] == 'R' ? +1
                                                                  : 0);
        rdy[i + 1] = rdy[i + 2] + (s[i] == 'D' ? -1 : s[i] == 'U' ? +1
                                                                  : 0);
    }

    vector<bool> ans(q);
    map<pair<int, int>, int> points;

    vector<array<int, 3>> f[2][n + 1], b[2][n + 1];
    vector<int> qf(q + 1), qb(q + 1);

    for (int i = 0; i < q; i++) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        if (x == 0 && y == 0) ans[i] = true;
        l--, r--;

        if (l > 0) {
            f[0][0].push_back({i, x, y});
            f[1][l - 1].push_back({i, x, y});
        }

        b[0][r].push_back({i, rdx[r + 2] + x - dx[l], rdy[r + 2] + y - dy[l]});
        b[1][l].push_back({i, rdx[r + 2] + x - dx[l], rdy[r + 2] + y - dy[l]});

        if (r < n - 1) {
            f[0][r + 1].push_back({i, x, y});
            f[1][n - 1].push_back({i, x, y});
        }
    }


    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        debug(i, f[0][i]);
        debug(i, f[1][i]);
        // register
        for (auto [j, x, y]: f[0][i]) {
            qf[j] = points[{x, y}];
        }

        x = dx[i + 1], y = dy[i + 1];
        points[{x, y}]++;

        // ans
        for (auto [j, x, y]: f[1][i]) {
            if (qf[j] != points[{x, y}]) {
                ans[j] = true;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        debug(i, b[0][i]);
        debug(i, b[1][i]);
        // register
        for (auto [j, x, y]: b[0][i]) {
            qb[j] = points[{x, y}];
        }

        x = rdx[i + 1], y = rdy[i + 1];
        points[{x, y}]++;

        // ans
        for (auto [j, x, y]: b[1][i]) {
            if (qb[j] != points[{x, y}]) {
                ans[j] = true;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        cout << (ans[i] ? "YES" : "NO") << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
