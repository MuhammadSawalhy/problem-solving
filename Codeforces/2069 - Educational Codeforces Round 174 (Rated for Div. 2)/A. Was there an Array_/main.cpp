#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int lst1 = -10;
    for (int i = 0; i < n - 2; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 2; i++) {
        if (a[i] && i - lst1 == 2) {
            cout << "NO\n";
            return;
        }
        if (a[i]) lst1 = i;
    }
    cout << "YES\n";
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
