// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

bool ismatch(char o, char c) {
    return o == '(' && c == ')' || o == '[' && c == ']';
}

string match(char c) {
    if (c == '[' || c == ']')
        return "[]";
    return "()";
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    string s, dp[101][101];
    int dpsize[101][101];
    cin.ignore();
    while (t--) {
        getline(cin, s);
        getline(cin, s); // silly case when the input is empty string

        int n = s.size();
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++)
                dp[i][j] = "", dpsize[i][j] = 1e9;
            dpsize[i][i] = 0;
            if (i < n) {
                dp[i][i + 1] = match(s[i]);
                dpsize[i][i + 1] = 2;
            }
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0, j = len; j <= n; i++, j++) {
                // split into [i, k), [k, j)
                for (int k = i + 1; k < j; k++)
                    if (dpsize[i][k] + dpsize[k][j] < dpsize[i][j]) {
                        dp[i][j] = dp[i][k] + dp[k][j];
                        dpsize[i][j] = dpsize[i][k] + dpsize[k][j];
                    }
                // split into s[i], s[i + 1]...s[j - 2], s[j - 1]
                if (ismatch(s[i], s[j - 1]) && dpsize[i + 1][j - 1] + 2 < dpsize[i][j]) {
                    if (s[i] == '[')
                        dp[i][j] = "[" + dp[i + 1][j - 1] + "]";
                    else
                        dp[i][j] = "(" + dp[i + 1][j - 1] + ")";
                    dpsize[i][j] = dpsize[i + 1][j - 1] + 2;
                }
            }
        }

        cout << dp[0][n] << endl;
        if (t) cout << endl;
    }

    return 0;
}
