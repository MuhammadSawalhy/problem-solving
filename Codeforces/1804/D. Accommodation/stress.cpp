/**
 *    author:  MaGnsi0
 *    created: 12.03.2023 17:08:29
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    assert(m % 4 == 0);
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans_min = 0, ans_max = 0;
    for (int i = 0; i < n; ++i) {
        int x = m / 4, y = m / 2;
        vector<bool> done(m, false);
        for (int j = 0; j + 1 < m; ++j) {
            if (x && a[i][j] == '1' && a[i][j + 1] == '1') {
                done[j] = done[j + 1] = true;
                ans_min++, x--, j++;
            }
        }
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '1' && !done[j]) {
                ans_min++;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        vector<int> dp(m, -1);
        function<int(int)> solve = [&](int j) {
            if (j == m) {
                return 0;
            }
            if (dp[j] != -1) {
                return dp[j];
            }
            dp[j] = solve(j + 1);
            if (j + 1 < m && a[i][j] != a[i][j + 1]) {
                dp[j] = max(dp[j], solve(j + 2) + 1);
            }
            if (j + 1 < m && a[i][j] == '0' && a[i][j + 1] == '0') {
                dp[j] = max(dp[j], solve(j + 2) + 1);
            }
            return dp[j];
        };
        int ans = solve(0), x = count(a[i].begin(), a[i].end(), '1');
        ans_max += x - max(0, m / 4 - ans);
    }
    cout << ans_min << " " << ans_max << endl;
}

