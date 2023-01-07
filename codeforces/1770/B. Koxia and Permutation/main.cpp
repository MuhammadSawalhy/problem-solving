// Date: 30-12-2022
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> ans(n);

    int i = 1, j = n, r = 0;
    while (i <= j) {
        for (int m = 0; r < n && m < k - 1; m++) {
            ans[r++] = j--;
        }
        if (r == n)
            break;
        ans[r++] = i++;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
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
