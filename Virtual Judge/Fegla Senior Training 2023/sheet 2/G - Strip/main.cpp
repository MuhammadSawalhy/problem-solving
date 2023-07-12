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

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, s, l; cin >> n >> s >> l; ll a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    int dp[n + 1];
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;

    multiset<int> DP, A;

    for (int i = 1, j = 1; i <= n; i++) {
        A.insert(a[i]);

        if (i - l + 1 >= j)
            DP.insert(dp[i - l]);

        while (*prev(A.end()) - *A.begin() > s) {
            if (DP.size())
                DP.erase(DP.find(dp[j - 1]));
            A.erase(A.find(a[j++]));
        }

        assert(DP.size() == max(0LL, i - l + 1 - j + 1));
        if (DP.size()) dp[i] = *DP.begin() + 1;
    }

    cout << (dp[n] > n ? -1 : dp[n]) << '\n';

    return 0;
}
