// ﷽
// https://codeforces.com/contest/1917/problem/E

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

int n, k;

void solve() {
}

mt19937 rng = mt19937(random_device()());

void seed(int s) { rng = mt19937(s); }

int rand_int(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

bool dp[10][100][1 << 10][2];
bool vis[10][100][1 << 10][2];

bool calcdp(int i, int sum, int mask, int row) {
    bool &res = dp[i][sum][mask][row];
    if (vis[i][sum][mask][row]) return res;
    vis[i][sum][mask][row] = true;
    if (i == n) {
        res = sum == 0 && (mask == 0 || mask == (1 << n) - 1);
        if (res) debug(mask, row);
        return res;
    }

    for (int cur = 0; cur < 1 << n; cur++) {
        if (__popcount(cur) % 2 != row) continue;
        if (__popcount(cur) > sum) continue;
        res |= calcdp(i + 1, sum - __popcount(cur), mask ^ cur, row);
        if (res) break;
    }

    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (true) {
        n = rand_int(1, 10);
        k = rand_int(1, n * n);
        set<int> valid;

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= i * i; j += i) {
                if (i < n && j % 2) continue;
                valid.insert(j);
            }
        }

        bool ok = false;
        memset(dp, 0, sizeof dp);
        memset(vis, 0, sizeof vis);

        ok |= calcdp(0, k, 0, 0);

        if (ok && !valid.count(k)) {
            debug("BAD");
            debug(n, k, 0);
            break;
        }

        ok |= calcdp(0, k, 0, 1);

        if (ok && !valid.count(k)) {
            debug("BAD");
            debug(n, k, 1);
            break;
        }

        debug(n, k, ok);
    }

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
