#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int x, y;
    cin >> x >> y;
    if (y == x + 1 || (y < x && (x - y + 1) % 9 == 0)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
