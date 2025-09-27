#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

void solve() {
    int n, k;
    cin >> n >> k;
    n -= min(n, k);
    if (n == 0) cout << 1 << endl;
    else cout << 1 + ((n + min(n, (k - (k & 1))) - 1) / min(n, (k - (k & 1)))) << endl;
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
