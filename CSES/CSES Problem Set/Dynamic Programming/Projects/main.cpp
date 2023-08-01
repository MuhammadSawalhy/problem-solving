// ﷽
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

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

const int N = 2e5;
int n;
array<int, 3> projects[N];
ll dp[N];

ll solve(int i) {
    if (i >= n) return 0;
    ll &ans = dp[i];
    if (~ans) return ans;

    int j = upper_bound(projects, projects + n, array<int, 3>{projects[i][1], (int)1e9, (int)1e9}) - projects;
    ans = max(solve(i + 1), projects[i][2] + solve(j));

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(dp, -1, sizeof dp);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> projects[i][0] >> projects[i][1] >> projects[i][2];
    }

    sort(projects, projects + n);
    cout << solve(0);

    return 0;
}
