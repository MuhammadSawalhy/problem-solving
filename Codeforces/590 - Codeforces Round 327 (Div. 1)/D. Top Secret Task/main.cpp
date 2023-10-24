// ﷽
// https://codeforces.com/contest/590/problem/D

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

constexpr int inf = 1e18, N = 155;
vector dp1(N, vector<int>(N *N, -inf));
vector dp2(N, vector<int>(N *N, inf));
vector<int> dp(N *N, inf), a(N);

void solve() {
    int n, k, s;
    cin >> n >> k >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (k == n) {
        cout << accumulate(all(a), 0LL) << endl;
        return;
    }

    if (s >= (n) * (n - 1) / 2) {
        sort(a.begin(), a.begin() + n);
        cout << accumulate(a.begin(), a.begin() +k, 0LL) << endl;
        return;
    }

    const int A = k * k;
    const int B = (n - k) * (n - k);

    dp1[0][0] = 0;
    for (int i = 0; i < k; i++) {
        for (int x = i; x >= 0; x--) {
            for (int c = max(0LL, x - (k - 1 - i)); c <= A; c++) {
                maxit(dp1[x + 1][c - x + (k - 1 - i)], dp1[x][c] + a[i]);
            }
        }
    }

    dp2[0][0] = 0;
    for (int i = k; i < n; i++) {
        for (int x = i - k; x >= 0; x--) {
            for (int c = 0; c < B; c++) {
                minit(dp2[x + 1][c - x + (i - k)], dp2[x][c] + a[i]);
            }
        }
    }

    int sum = accumulate(a.begin(), a.begin() + k, 0LL);

    for (int x = 0; x <= min(k, n - k); x++) {
        for (int c1 = 0; c1 < A; c1++) {
            for (int c2 = 0; c2 < B; c2++) {
                minit(dp[c1 + c2 + x * x], -dp1[x][c1] + dp2[x][c2] + sum);
            }
        }
    }

    int ans = inf;
    for (int i = 0; i <= s; i++)
        minit(ans, dp[i]);

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
