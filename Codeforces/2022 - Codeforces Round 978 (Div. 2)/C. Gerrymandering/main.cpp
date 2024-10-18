// ﷽
// https://codeforces.com/contest/2022/problem/C

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

bool calA(const char &a, const char &b, const char &c) {
    int cnt = 0;
    if (a == 'A') cnt++;
    if (b == 'A') cnt++;
    if (c == 'A') cnt++;
    return cnt >= 2;
}

const int N = 1e5 + 5, inf = 1e18;
int dp[N + 1][4][4];
int n;
string a[2];

int doit(int i, int x, int y) {
    if (x >= 3 || y >= 3) return -inf;

    if (i == n) {
        if (x == 0 && y == 0) return 0;
        return -inf;
    }

    if (dp[i][x][y] != -inf) return dp[i][x][y];
    auto &ret = dp[i][x][y];

    ret = 0;
    ret = max(ret, doit(i + 1, x + 1, y + 1));

    if (x == 1 && y == 1) {
        ret = max(ret, doit(i + 1, 0, 1) + calA(a[0][i], a[0][i - 1], a[1][i - 1]));
        ret = max(ret, doit(i + 1, 1, 0) + calA(a[1][i], a[0][i - 1], a[1][i - 1]));
    }

    if (x == 1 && y == 0) {
        ret = max(ret, doit(i + 1, 0, 0) + calA(a[0][i], a[0][i - 1], a[1][i]));
    }

    if (x == 0 && y == 1) {
        ret = max(ret, doit(i + 1, 0, 0) + calA(a[1][i], a[1][i - 1], a[0][i]));
    }

    if (x == 2) {
        ret = max(ret, doit(i + 1, 0, y + 1) + calA(a[0][i], a[0][i - 1], a[0][i - 2]));
    }

    if (y == 2) {
        ret = max(ret, doit(i + 1, x + 1, 0) + calA(a[1][i], a[1][i - 1], a[1][i - 2]));
    }

    if (x == 2 && y == 2) {
        ret = max(ret, doit(i + 1, 0, 0) + calA(a[1][i], a[1][i - 1], a[1][i - 2]) + calA(a[0][i], a[0][i - 1], a[0][i - 2]));
    }

    debug(i, x, y, ret);

    return ret;
}

void solve() {
    cin >> n;
    cin >> a[0] >> a[1];

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                dp[i][j][k] = -inf;
            }
        }
    }

    cout << doit(0, 0, 0) << '\n';
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
