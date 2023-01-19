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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int sticks[k];
    for (int i = 0; i < k; i++) cin >> sticks[i];

    string ans(n + 1, 'L');
    for (int i = 1; i <= n; i++) {
        bool wins = false;
        for (int j = 0; j < k; j++) {
            if (sticks[j] <= i) wins |= ans[i - sticks[j]] == 'L';
            if (wins) break;
        }
        ans[i] = wins ? 'W' : 'L';
    }

    cout << ans.substr(1);

    return 0;
}
