#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> fr;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        fr[a[i]]++;
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int rem = 0;
    for (int i = 0; i < a.size(); i++) {
        int f = fr[a[i]];

        if (i > 0)
            rem -= 2 * (a[i] - a[i - 1] - 1);

        if (rem < 0 && abs(rem) % 2 == 1) {
            cout << "No\n";
            return;
        } else if (rem < 0) rem = 0;

        if (f + rem <= 1) {
            cout << "No\n";
            return;
        } else {
            rem = f + rem - 2;
        }
    }

    if (rem % 2 == 1) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
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
