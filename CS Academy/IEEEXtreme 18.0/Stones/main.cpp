// ﷽
// https://csacademy.com/ieeextreme18/task/stones/

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
#define vii vector<pii>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 41;
double dp[N][N][N][N];
bool vis[N][N][N][N];
int r1, b1, r2, b2;

double dfs(int r, int b, int pr, int pb) {
    if (r <= 0 || b <= 0) return 0;
    if (pr <= 0 || pb <= 0) return 1;
    auto &ret = dp[r][b][pr][pb];
    if (vis[r][b][pr][pb]) return ret;
    vis[r][b][pr][pb] = true;

    int steps = r1 - r + b1 - b + r2 - pr + b2 - pb;
    debug(r, b, pr, pb, steps);

    ret = max(0.5 * (1 - dfs(r - 1, b, pr, pb)) + 0.5 * (1 - dfs(r, b, pr - 1, pb)),
              0.5 * (1 - dfs(r, b - 1, pr, pb)) + 0.5 * (1 - dfs(r, b, pr, pb - 1)));

    return ret;
}

void solve() {
    cin >> r1 >> b1 >> r2 >> b2;

    memset(dp, -1, sizeof dp);
    cout << fixed << setprecision(9) << dfs(r1, b1, r2, b2) << endl;
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
