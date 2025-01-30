#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = 0;
    multiset<int> s;
    for (int i = n - 1; i >= 0; i--) {
        if (s.count(k - a[i])) {
            ans++;
            s.erase(s.find(k - a[i]));
        } else {
            s.insert(a[i]);
        }
    }
    cout << ans << '\n';
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
