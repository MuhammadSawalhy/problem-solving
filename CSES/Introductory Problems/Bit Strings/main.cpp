// Date: 02-01-2023
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    int ans = 1;
    int mod = 1e9 + 7;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ans *= 2;
        ans %= mod;
    }

    cout << ans;

    return 0;
}
