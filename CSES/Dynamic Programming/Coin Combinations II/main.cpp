// ﷽
// 12 جُمادى الآخرة 1444
// Jan 04, 2023
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

constexpr int mod = (int) 1e9 + 7;
int dp[(int)1e6+1];
int c[100], n, x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++) scanf("%d", &c[i]);

    dp[0] = 1;

    for (int j = 0; j < n; j++)
        for (int i = c[j]; i <= x; i++) {
            dp[i] -= ((dp[i] += dp[i - c[j]]) >= mod) ? mod : 0;
    }

    printf("%d", dp[x]);

    return 0;
}
