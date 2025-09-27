#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

void solve() {
    int x, y, a;
    cin >> x >> y >> a;

    int cnt = a / (x + y);
    a -= cnt * (x + y);

    if (a < x) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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
