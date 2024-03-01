// ﷽
// https://cses.fi/problemset/task/2137

#pragma GCC target("popcnt")
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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    bitset<3000> grid[n];

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    long long ans = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int x = (grid[i] & grid[j]).count();
            ans += x * (x - 1) / 2;
        }
    }

    cout << ans << endl;

    return 0;
}
