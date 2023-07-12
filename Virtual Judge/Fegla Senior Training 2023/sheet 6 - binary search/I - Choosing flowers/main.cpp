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

void solve() {
    int n, m;
    cin >> n >> m;
    pair<int, int> flowers[m];
    ll a[m], A[m];

    for (int i = 0; i < m; i++)
        cin >> flowers[i].first >> flowers[i].second, a[i] = flowers[i].first;

    ll ans = 0;
    sort(a, a + m);

    for (int i = 0; i < m; i++)
        A[i] = a[i], A[i] += i > 0 ? A[i - 1] : 0;

    for (int i = 0; i < m; i++) {
        int j = upper_bound(a, a + m, flowers[i].second) - a;
        j = max(j, m - n);
        if (flowers[i].first > flowers[i].second)
            ans = max(ans, (n - (m - j)) * flowers[i].second + A[m - 1] - (j > 0 ? A[j - 1] : 0));
        else
            ans = max(ans, (n - (m - j) - 1) * flowers[i].second + flowers[i].first + A[m - 1] - (j > 0 ? A[j - 1] : 0));
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
