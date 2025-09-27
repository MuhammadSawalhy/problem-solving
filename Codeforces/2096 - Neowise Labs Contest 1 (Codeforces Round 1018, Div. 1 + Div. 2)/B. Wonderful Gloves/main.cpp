#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }

    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (l[i] > r[i]) swap(l[i], r[i]);
    }

    sort(all(l));

    for (int i = 0; i < n; i++) {
        ans += r[i];
    }

    for (int i = n - k + 1; i < n; i++) ans += l[i];
    ans++;

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
