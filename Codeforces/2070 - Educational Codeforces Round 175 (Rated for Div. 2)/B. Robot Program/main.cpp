#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

void solve() {
    int n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;

    int i;
    for (i = 0; i < n && x != 0; i++) {
        x += s[i] == 'L' ? -1 : +1;
    }

    if (x == 0 && k >= i) {
        int ans = 1;
        k -= i;

        x += s[0] == 'L' ? -1 : +1;
        for (i = 1; i < n && x != 0; i++) {
            x += s[i] == 'L' ? -1 : +1;
        }

        if (x == 0) {
            ans += k / i;
        }

        cout << ans << endl;
    } else {
        cout << 0 << endl;
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
