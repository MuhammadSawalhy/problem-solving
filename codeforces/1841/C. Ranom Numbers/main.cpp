// ﷽
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

const int N = 2e5;

int n;
string s;
int dp[N][5][2];

int solve(int i, int mx, bool done) {
    if (i >= n) return 0;

    int &ans = dp[i][mx][done];
    if (~ans) return ans;

    int val = s[i] - 'A';
    ans = solve(i + 1, max(mx, val), done) + pow(10, val) * (mx > val ? -1 : 1);
    debug(val, pow(10, val) * (mx > val ? -1 : 1));

    if (!done) {
        for (int newval = 0; newval < 5; newval++) {
            ans = max(ans, solve(i + 1, max(mx, newval), true) + (int)pow(10, newval) * (mx > newval ? -1 : 1));
        }
    }


    return ans;
}

void solve() {
    cin >> s;
    n = s.length();
    reverse(all(s));
    debug(s);

    for (int i = 0; i < n; i++) {
        for (int mx = 0; mx < 5; mx++) {
            for (int done = 0; done < 2; done++) {
                dp[i][mx][done] = -1;
            }
        }
    }

    cout << solve(0, 0, 0) << endl;
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
