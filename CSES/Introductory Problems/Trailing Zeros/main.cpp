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
    cin >> n;
    ll ans = 0;

    // count number of fives in the factorial
    for (int i = 5; i <= n; i *= 5) {
        ans += n / i;
    }

    cout << ans;

    return 0;
}
