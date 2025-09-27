#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

void solve() {
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    assert(r - l + 1 == n + 1);

    int d = min(n - m, -l);
    l += d;
    n -= d;
    d = min(n - m, r);
    r -= d;
    n -= d;
    assert(n == m);
    cout << l << ' ' << r << endl;
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
