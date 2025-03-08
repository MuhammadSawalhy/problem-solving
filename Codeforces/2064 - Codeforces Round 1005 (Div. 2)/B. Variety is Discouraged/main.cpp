#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    map<int, int> fr;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        fr[a[i]]++;
    }

    for (int i = 0; i < n; i++) {
        b[i] = fr[a[i]] == 1;
    }

    int lst = -1;
    int l, r, mx = 0;
    for (int i = 0; i < n; i++) {
        if (b[i]) {
            if (i - lst > mx) {
                mx = i - lst;
                l = lst + 1;
                r = i;
            }
        } else {
            lst = i;
        }
    }

    if (mx == 0) {
        cout << 0 << endl;
    } else {
        cout << l + 1 << ' ' << r + 1 << endl;
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
