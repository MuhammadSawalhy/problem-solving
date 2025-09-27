#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

void solve() {
    int n, k;
    cin >> n >> k;
    int l = 0, r = 2 * n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        vector<bool> vis(n + 4);
        int cnt = 0;
        for (int i = 0, j; i < n;) {
            int mex = 0;
            j = i;
            while (j < n) {
                if (a[j] < n + 2)
                    vis[a[j]] = 1;
                j++;
                while (vis[mex]) mex++;
                if (mex >= mid) break;
            }
            for (int k = i; k < j; k++) {
                if (a[k] < n)
                    vis[a[k]] = false;
            }
            i = j;
            cnt += mex >= mid;
        }
        if (cnt >= k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
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
