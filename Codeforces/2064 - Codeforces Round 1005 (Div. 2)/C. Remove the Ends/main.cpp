#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans(n);

    for (int i = 0, v = 0; i < n; i++) {
        v += max(a[i], 0ll);
        ans[i] = v;
    }

    for (int i = n - 1, v = 0; i >=0; i--) {
        v += max(-a[i], 0ll);
        ans[i] += v;
    }

    cout << *max_element(ans.begin(), ans.end()) << endl;
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
