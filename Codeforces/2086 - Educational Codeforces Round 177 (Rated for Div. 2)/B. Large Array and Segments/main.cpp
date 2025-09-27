#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    int sum = 0;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int cnt = (x + sum - 1) / sum;

    if (cnt > k) {
        cout << 0 << endl;
        return;
    }

    int ans = (k - cnt) * n;

    x -= sum * (cnt - 1);

    for (int i = 0; i < n;i++) {
        if (sum < x) break;
        sum -= a[i];
        ans++;
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
