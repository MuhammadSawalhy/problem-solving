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

    int n, x;
    cin >> n >> x;

    int a[n];
    int ans = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];


    vector<long long> res;
    for (int mask = 0; mask < (1 << n / 2); mask++) {
        long long s = 0;
        for (int i = 0; i < n / 2; i++) {
            if ((mask >> i) & 1)
                s += a[i];
        }
        res.push_back(s);
    }

    sort(all(res));

    for (int mask = 0; mask < (1 << (n + 1) / 2); mask++) {
        long long s = 0;
        for (int i = 0; i < (n + 1) / 2; i++) {
            if ((mask >> i) & 1)
                s += a[i + n / 2];
        }
        ans += upper_bound(all(res), x - s) - lower_bound(all(res), x - s);
    }

    cout << ans << endl;

    return 0;
}
