#include <bits/stdc++.h>
using namespace std;

const int N = 300300, lg = 20, mod = 1e9 + 7;
int fact[N], fact_inv[N];

int ncr(int n, int r) {
    if (r > n || n < 0) return 0;
    return 1LL * fact[n] * fact_inv[r] % mod * fact_inv[n - r] % mod;
}

unordered_map<int, int> dp[lg][100];

int nn;

int solveit(int n, int cnt, int sum) {
    if (dp[cnt][sum].count(n)) return dp[cnt][sum][n];
    auto &res = dp[cnt][sum][n];

    if (sum > nn) return res = 0;

    if (n == 1) {
        int s = nn - sum, b = cnt;
        return res = ncr(s + b, s);
    }

    res = 0;
    for (int d = 2; d <= 9; d++) {
        if (n % d == 0)
            res = (res + solveit(n / d, cnt + 1, sum + d)) % mod;
    }

    return res;
}

void solve() {
    cin >> nn;
    cout << solveit(nn, 0, 0) << endl;
    for (int i = 0; i < lg; i++)
        for (int sum = 0; sum < 100; sum++) dp[i][sum].clear();
}

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (1LL * res * a) % mod;
        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return res;
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = (1LL * fact[i - 1] * i) % mod;
    fact_inv[N - 1] = power(fact[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) fact_inv[i] = (1LL * fact_inv[i + 1] * (i + 1)) % mod;

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
