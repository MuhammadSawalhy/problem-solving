// ﷽
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;


int minSwaps(vector<int> &a) {
    int n = a.size();
    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i] = {a[i], i};
    }

    int adjinv = 0;

    for (int i = 1; i < n; i++) {
        if (a[i - 1] - 1 == a[i] && a[i - 1] == i + 1) {
            adjinv++;
        }
    }

    sort(all(arr));

    int ans = 0;
    vector<bool> vis(n);

    for (int i = 0; i < n; i++) {
        if (vis[i] == true || arr[i].second == i) continue;

        int clen = 0;
        int j = i;

        while (vis[j] == false) {
            vis[j] = true;
            clen++;
            j = arr[j].second;
        }

        ans += (clen - 1);
    }

    if (adjinv)
        ans--;
    else
        ans++;

    return ans;
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = minSwaps(a);
    cout << ans << endl;
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
