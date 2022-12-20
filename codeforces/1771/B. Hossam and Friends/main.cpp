// Date: 11-12-2022
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef LOCAL
#include "debug.hpp"
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> left(n, -1);

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (l > r)
            swap(l, r);
        left[r] = max(left[r], l);
    }

    ll ans = 0;
    int mxleft = -1;
    for (int i = 0; i < n; i++) {
        mxleft = max(mxleft, left[i]);
        ans += i - mxleft;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
