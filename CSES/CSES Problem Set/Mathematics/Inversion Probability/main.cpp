#include <bits/stdc++.h>
#include <cmath>
#include <quadmath.h> // For __float128 and related functions

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

    __float128 ans = 0;

    int f[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        for (int j = 1; j < i; j++) {
            int cnt = 0;
            for (int r = 1; r <= f[j]; r++) {
                cnt += min(r - 1, f[i]);
            }
            ans += (__float128)cnt * 1e6 / (f[i] * f[j]);
        }
    }

    auto d = ans - (int) ans;
    int res = 0;
    if (d == 0.5) {
        res = (int) ans;
        if (res & 1) res++;
    } else if (d > 0.5) {
        ans += 1;
        res = (int) ans;
    } else {
        res = (int) ans;
    }

    // Print the result with six decimal places
    cout << fixed << setprecision(6) << res / 1e6 << endl;

    return 0;
}
