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

    int n, k;
    cin >> n >> k;

    int a[n + 1];
    ll ps[n + 1];
    ps[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) ps[i] = ps[i - 1] + a[i];

    int occ = 0, value;
    for (int i = 1; i <= n; i++) {
        int s = 0, e = i;
        while (e - s > 1) {
            int m = (s + e) / 2;
            if (1LL * (i - m + 1) * a[i] - ps[i] + ps[m - 1] <= k) {
                e = m;
            } else {
                s = m;
            }
        }
        assert(e > 0 && e <= i);
        if (i - e + 1 > occ) {
            occ = i - e + 1;
            value = a[i];
        }
    }

    cout << occ << " " << value;

    return 0;
}
