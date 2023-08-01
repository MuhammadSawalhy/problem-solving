// ﷽
#include <bits/stdc++.h>

using namespace std;

constexpr int mod = 1e9 + 7;
int dp[(int) 1e6 + 7], c[100], n, x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++) scanf("%d", &c[i]);

    dp[0] = 1;
    long long tmp;
    for (int i = 1; i <= x; i++) {
        tmp = 0;
        for (int j = 0; j < n; j++)
            if (i >= c[j]) tmp += dp[i - c[j]];
        dp[i] = tmp % mod;
    }

    printf("%d", dp[x]);

    return 0;
}
