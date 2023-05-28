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

const int N = 20;
int n, x, w[N];
pair<int32_t, int32_t> dp[1 << N];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> w[i];

    vector<int> masks;
    for (int i = 0; i < 1 << n; i++)
        masks.push_back(i);

    sort(all(masks), [](int l, int r) { return __builtin_popcount(l) < __builtin_popcount(r); });

    memset(dp, 0x3f, sizeof dp);
    dp[0] = {1, 0};

    for (auto mask: masks) {
        auto &a = dp[mask];
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) continue;
            auto &b = dp[mask | (1 << i)];
            pair<int32_t, int32_t> newvalue;
            if (a.second + w[i] <= x) newvalue = {a.first, a.second + w[i]};
            else newvalue = {a.first + 1, w[i]};
            if (newvalue < b)
                b = newvalue;
        }
    }

    cout << dp[(1 << n) - 1].first;

    return 0;
}
