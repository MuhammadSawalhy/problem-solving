// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define int    long long
#define ll     long long
#define all(v) v.begin(), v.end()

const int N = 81;
map<vector<bool>, int> dp[N * (N - 1) / 2];
int n;

int solve(vector<bool> state, int steps) {
    if (dp[steps].count(state)) return dp[steps][state];

    int res = 0;

    if (steps == 0) {
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (state[i]) {
                y += x;
                x = 0;
            } else {
                x++;
                res += y;
            }
        }
    } else {
        vector<bool> newstate = state;
        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0 && state[i] ^ state[i - 1]) {
                newstate[i] = newstate[i] ^ 1;
                newstate[i - 1] = newstate[i - 1] ^ 1;
                res = max(res, solve(newstate, steps - 1));
                newstate[i] = newstate[i] ^ 1;
                newstate[i - 1] = newstate[i - 1] ^ 1;
            }
            if (i + 1 < n && state[i] ^ state[i + 1]) {
                newstate[i] = newstate[i] ^ 1;
                newstate[i + 1] = newstate[i + 1] ^ 1;
                res = max(res, solve(newstate, steps - 1));
                newstate[i] = newstate[i] ^ 1;
                newstate[i + 1] = newstate[i + 1] ^ 1;
            }
        }
    }

    return dp[steps][state] = res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    vector<bool> a(n);
    for (int i = 0, x; i < n; i++)
        cin >> x, a[i] = x;


    int ans[n * (n - 1) / 2 + 1];
    for (int i = 0; i <= n * (n - 1) / 2; i++) {
        ans[i] = solve(a, i);
        if (i > 0) ans[i] = max(ans[i], ans[i - 1]);
        cout << ans[i] << " ";
    }

    return 0;
}
