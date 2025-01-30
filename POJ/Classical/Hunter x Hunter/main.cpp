#include <bits/stdc++.h>
using namespace std;

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s[n + 1];
        int dp[n + 1][n + 1];
        for (int i = 1; i <= n; i++) cin >> s[i], s[i] = " " + s[i];
        bool flag = false;
        if (s[1][1] != '*') s[1][1] = '*', flag = true;
        memset(dp, 0, sizeof dp);
        dp[1][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i][j] == '#') continue;
                if (dp[i - 1][j])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + (s[i][j] == '*'));
                if (dp[i][j - 1])
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + (s[i][j] == '*'));
            }
        }

        bool can = dp[n][n] != 0;
        cout << (can ? dp[n][n] - flag : -1) << endl;
    }

    return 0;
}
