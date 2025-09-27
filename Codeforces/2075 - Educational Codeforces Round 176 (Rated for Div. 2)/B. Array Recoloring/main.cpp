#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (k == 1) {
        int ans = a[0] + a[n - 1];
        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, a[i] + max(a[0], a[n - 1]));
        }
        cout << ans << endl;
        return;
    }

    sort(rall(a));
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        ans += a[i];
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
