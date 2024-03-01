// ﷽
// https://codeforces.com/contest/1927/problem/G

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

const int N = 102;
int n;
vector<int> a(N);
int dp[N][N][N];

int solve(int i, int rem, int blocked) {
    int &ret = dp[i][rem][blocked];
    if (ret != -1) return ret;
    if (i >= n - 1) return ret = rem == 0;
    if (i == blocked) return ret = solve(i + 1, rem - 1, blocked);
    debug(i, rem, blocked);

    ret = 1e18;
    // can use to the right
    int use_right = solve(i + 1, max(rem - 1, a[i] - 1), blocked);
    minit(ret, use_right + 1);
    if (rem) {
        // can skip
        debug("skiping i");
        minit(ret, solve(i + 1, rem - 1, blocked));
    } else {
        // or search for one to the right of i, that will be taken left
        debug("searching for j > i");
        assert(blocked < i || blocked == n);
        for (int j = i + 1; j < n; j++) {
            if (j - a[j] + 1 <= i) 
                minit(ret, solve(i + 1, j - i, j) + 1);
        }
    }

    return ret;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    debug(n);
    debug_itr(a.begin(), a.begin() + n);

    // init dp
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) dp[i][j][k] = -1;
        }
    }

    cout << solve(0, 0, n) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
