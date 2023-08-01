// ﷽
// 12 جُمادى الآخرة 1444
// Jan 04, 2023
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

    int n, q;
    cin >> n >> q;
    ll a[n], b[n];
    int index[n + 1];
    for (int i = 0; i < n; i++) cin >> a[i], b[i] = a[i], index[a[i]] = i;

    // relative order
    // remember sorting stability

    sort(a, a + n);

    int ans = 1;

    // count number of adjacent inversions
    for (int i = 1; i < n; i++)
        ans += index[a[i]] < index[a[i - 1]];

    int x, y;
    int i, j;
    while (q--) {
        cin >> i >> j;
        i--, j--;
        // adjacent inversions before and after swapping
        x = (b[i] > 1 && index[b[i]] < index[b[i] - 1]) + (b[i] < n && index[b[i]] > index[b[i] + 1]);
        x += (b[j] > 1 && b[j] - 1 != b[i] && index[b[j]] < index[b[j] - 1]) + (b[j] < n && b[j] + 1 != b[i] && index[b[j]] > index[b[j] + 1]);
        index[b[i]] = j;
        index[b[j]] = i;
        swap(b[i], b[j]);
        y = (b[i] > 1 && index[b[i]] < index[b[i] - 1]) + (b[i] < n && index[b[i]] > index[b[i] + 1]);
        y += (b[j] > 1 && b[j] - 1 != b[i] && index[b[j]] < index[b[j] - 1]) + (b[j] < n && b[j] + 1 != b[i] && index[b[j]] > index[b[j] + 1]);
        ans += y - x;
        cout << ans << endl;
    }

    return 0;
}
