#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt[30]{};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 30; j++) {
            cnt[j] += (a[i] >> j) & 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < 30; j++) {
            int x = cnt[j];
            if ((a[i] >> j) & 1) {
                cur += (n - x) << j;
            } else {
                cur += x << j;
            }
        }
        ans = max(ans, cur);
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
