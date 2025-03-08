#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

// 0, 0, 0
// 1, 1, 1
// 2, 2, 2
// 3, 0, 3
// 4, 1, 4
// 5, 2, 0
// 6  0, 1
// 7, 1, 2
// 8, 2, 3
// 9, 0, 4
// 10, 1, 0
// 11, 2, 1
// 12, 0, 2
// 13, 1, 3
// 14, 2, 4
// 15, 0, 0

void solve() {
    int n;
    cin >> n;

    if (n < 15) cout << min(n + 1, 3ll) << endl;
    else {
        int x = n / 15 * 15;
        int ans = n / 15 * 3;
        for (int i = x; i <= n; i++) ans += (i % 3) == (i % 5);
        cout << ans << endl;
    }
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
