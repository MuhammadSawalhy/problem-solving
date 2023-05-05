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

    int n, m;
    cin >> n >> m;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int fr[1000];
    memset(fr, 0, sizeof fr);

    for (int i = 0; i < n; i++) {
        fr[a[i] % m]++;
    }

    for (int i = 0; i < m; i++) {
        if (fr[i] > 1)
            return cout << 0 << endl, 0;
    }

    sort(a, a + n);

    int ans = 1;
    for (int i = n - 1; i > -1; i--) {
        int res = 1;
        for (int j = i + 1; j < n; j++) {
            res = res * (a[j] - a[i]) % m;
        }
        debug(i, a[i], res);
        ans = (ans * res) % m;
    }

    cout << ans << endl;

    return 0;
}
