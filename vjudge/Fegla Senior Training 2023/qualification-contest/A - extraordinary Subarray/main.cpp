// ﷽
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

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

    int n;
    cin >> n;

    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int prev[n + 1][30];

    for (int j = 0; j < 30; j++) {
        prev[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 30; j++) {
            if (a[i] >> j & 1)
                prev[i][j] = i;
            else
                prev[i][j] = prev[i - 1][j];
        }
    }

    ll ans = 0;

    int k = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 30; j++) {
            if (a[i] >> j & 1)
                k = max(k, prev[i - 1][j]);
        }
        ans += i - k;
    }

    cout << ans << endl;

    return 0;
}
