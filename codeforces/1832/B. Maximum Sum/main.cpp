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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a));


    long long ans = 0;

    int i = 2 * k;
    int j = n;

    long long sum = 0;
    for (int r = i; r < j; r++) {
        sum += a[r];
    }

    ans = max(ans, sum);
    debug(a);

    while (i >= 2) {
        i -= 2;
        sum += a[i] + a[i + 1];

        j--;
        sum -= a[j];

        debug(i, j);

        ans = max(ans, sum);
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
