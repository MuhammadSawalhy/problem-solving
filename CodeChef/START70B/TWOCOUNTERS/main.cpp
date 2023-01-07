// Date: 21-12-2022
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

void solve() {
    int n, m;
    cin >> n >> m;

    int t[m];
    int type[m];
    for (int i = 0; i < m; i++) cin >> t[i];
    for (int i = 0; i < m; i++) cin >> type[i];

    // dp won't work
    // seems like greedy

    // keep (a - b) in { 2, 1, 0, -1, -2 }
    // I will either take it or sacrifice to take next opposite even type

    int dp[n + 1][5];
    // { 2, 1, 0, -1, -2 }
    // { 4, 3, 2,  1,  0 }
    memset(dp, 0, sizeof dp);

    int r = 0;

    debug(n, m);

    int new_dp[5];
    for (int i = 1; i <= n; i++) {
        while (r < m && t[r] < i) {
            r++;
        }
        for (int j = 0; j < 5; j++)
            new_dp[j] = dp[i][j];
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                // j, k -> new_i
                // 0, 0 -> i
                // 0, 1 ->
                int new_i = i - abs(j - k);
                if (new_i < 0) continue;
                int extra = 0;

                int q = j > k ? k + 1 : k - 1;
                int rr = r;
                while (rr > 0 && t[rr] >= new_i) {
                    rr--;
                }
                bool ok = true;
                for (int w = new_i + 1; w <= i; w++) {
                    while (rr < m && t[rr] < w) {
                        rr++;
                    }
                    if (rr < m && t[rr] == w) {
                        if (type[rr] == 2 && q > 2 || type[rr] == 1 && q < 2) {
                            ok = false;
                            break;
                        } else {
                            extra++;
                        }
                    }
                    q = j > k ? q + 1 : q - 1;
                }
                if (!ok) continue;
                debug(j, k, i, new_i, new_dp[j], dp[new_i][k], extra);
                new_dp[j] = max(new_dp[j], dp[new_i][k] + extra);
            }
        }
        for (int j = 0; j < 5; j++)
            dp[i][j] = new_dp[j];
    }

    int ans = 0;
    for (int i = 0; i < 5; i++)
        ans = max(ans, dp[n][i]);
    cout << ans << endl;
}

void another_trial() {
    int n, m;
    cin >> n >> m;

    int t[m];
    int type[m];
    for (int i = 0; i < m; i++) cin >> t[i];
    for (int i = 0; i < m; i++) cin >> type[i];

    constexpr int inf = 1e9;
    vector<vector<int>> dp(n + 1, vector<int>(5, -inf));
    int r = 0;// index of next event
    dp[0][2] = 0;
    for (int i = 1; i <= n; i++) {
        while (r < m && t[r] < i) r++;
        for (int j = 0; j < 5; j++) {
            if (r < m && t[r] == i && type[r] == 1 && j < 2)
                dp[i][2] = max(dp[i][2], dp[i - 1][j]);// this j is impossible to get
            else if (r < m && t[r] == i && type[r] == 2 && j > 2)
                dp[i][2] = max(dp[i][2], dp[i - 1][j]);// this j is impossible to get
            else if (j == 2)
                dp[i][2] = max({dp[i][2], dp[i - 1][1], dp[i - 1][3], r < m && t[r] == i ? dp[i - 1][2] : -inf});
            else {
                if (j < 4) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + (r < m && t[r] == i));
                }
                if (j > 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (r < m && t[r] == i));
                }
            }
        }
    }

    debug(dp);

    int ans = 0;
    for (int i = 0; i < 5; i++)
        ans = max(ans, dp[n][i]);
    cout << ans << endl;
}

constexpr int inf = 1e9;
vector<vector<int>> dp;
vector<int> t;
vector<int> type;
int n, m;

int solveit(int minute, int d, int next_event) {
    if (minute > n) return 0;
    if (d > 4 || d < 0) return 0;

    int &r = dp[minute][d];
    if (~r) {
        return r;
    }

    r = 0;

    if (next_event < m && t[next_event] == minute) {
        if (d + 1 > 2 && type[next_event] == 1 || d + 1 < 2 && type[next_event] == 2)
            r = max(r, solveit(minute + 1, d + 1, next_event + 1) + 1);
        else
            r = max(r, solveit(minute + 1, 2, next_event + 1));
        if (d - 1 > 2 && type[next_event] == 1 || d - 1 < 2 && type[next_event] == 2)
            r = max(r, solveit(minute + 1, d - 1, next_event + 1) + 1);
        else
            r = max(r, solveit(minute + 1, 2, next_event + 1));
    } else {
        r = max({ r, solveit(minute + 1, d + 1, next_event), solveit(minute + 1, d - 1, next_event) });
    }

    return r;
}

void recursiveDP() {
    cin >> n >> m;
    t.resize(m);
    type.resize(m);

    for (int i = 0; i < m; i++) cin >> t[i];
    for (int i = 0; i < m; i++) cin >> type[i];

    dp = vector<vector<int>>(n + 1, vector<int>(5, -1));

    cout << solveit(1, 2, 0) << endl;
    debug(dp);
}

int main() {
    int t;
    cin >> t;
    while (t--)
        recursiveDP();
    return 0;
}
