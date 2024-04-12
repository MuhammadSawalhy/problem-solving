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
    int n, k;
    cin >> n >> k;
    debug(n, k);

    if (k & 1) {
        cout << "No\n";
        return;
    }

    if (n == 2) {
        cout << "Yes\n";
        switch (k) {
            case 0:
                cout << "0 0\n";
                cout << "0 0\n";
                break;
            case 2:
                cout << "1 1\n";
                cout << "0 0\n";
                break;
            case 4:
                cout << "1 1\n";
                cout << "1 1\n";
                break;
        }
        return;
    }

    bool inverse = k > n * n / 2;
    if (inverse) k = n * n - k;
    debug(k);

    if (k == 2) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    vector<string> mat(n, string(n, '0'));

    if (k % 4 == 2) {
        mat[0][0] = '1';
        mat[1][0] = '1';
        mat[0][1] = '1';

        mat[1][2] = '1';
        mat[2][2] = '1';
        mat[2][1] = '1';
        k -= 6;
    }

    assert(k % 4 == 0);
    for (int i = 0; k && i + 1 < n; i++) {
        for (int j = 0; k && j + 1 < n; j++) {
            if (mat[i][j] == '0' && mat[i][j + 1] == '0') {
                if (mat[i + 1][j] == '0' && mat[i + 1][j] == '0') {
                    // set all to '1'
                    mat[i][j] = mat[i][j + 1] = mat[i + 1][j] = mat[i + 1][j + 1] = '1';
                    k -= 4;
                }
            }
        }
    }

    if (inverse) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = '0' + !(mat[i][j] - '0');
            }
        }
    }

    for (auto &m: mat) {
        for (auto c : m) cout << c << ' ';
        cout << endl;
    }
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

    // while (true) {
    //     n = rand_int(1, 10);
    //     k = rand_int(1, n * n);
    //     set<int> valid;
    //
    //     for (int i = 1; i <= n; i++) {
    //         for (int j = i; j <= i * i; j += i) {
    //             if (i < n && j % 2) continue;
    //             valid.insert(j);
    //         }
    //     }
    //
    //     bool ok = false;
    //     memset(dp, 0, sizeof dp);
    //     memset(vis, 0, sizeof vis);
    //
    //     ok |= calcdp(0, k, 0, 0);
    //
    //     if (ok && !valid.count(k)) {
    //         debug("BAD");
    //         debug(n, k, 0);
    //         break;
    //     }
    //
    //     ok |= calcdp(0, k, 0, 1);
    //
    //     if (ok && !valid.count(k)) {
    //         debug("BAD");
    //         debug(n, k, 1);
    //         break;
    //     }
    //
    //     debug(n, k, ok);
    // }

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
