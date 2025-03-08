#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // vector<int> vals;
    // for (int i = 0, j = 0; i < n;) {
    //     if (s[i] == 'R') {
    //         i++;
    //         continue;
    //     }
    //     int mx = 0;
    //     j = i;
    //     while (j < n && s[j] == 'B') mx = max(mx, a[j++]);
    //     vals.push_back(mx);
    //     i = j;
    // }
    //
    // sort(rall(vals));
    //
    // if (k >= vals.size()) cout << "0\n";
    // else cout << vals[k] << '\n';

    int l = -1, r = 1e9;

    while (r - l > 1) {
        int m = (r + l) / 2;

        vector<int> vals;
        for (int i = 0, j = 0; i < n;) {
            if (s[i] == 'R') {
                i++;
                continue;
            }
            int mx = 0;
            j = i;
            while (j < n && (s[j] == 'B' || a[j] <= m)) mx = max(mx, a[j++]);
            vals.push_back(mx);
            i = j;
        }

        sort(rall(vals));
        bool ok = k >= vals.size() || vals[k] <= m;
        if (ok) r = m;
        else l = m;

    }

    cout << r << endl;
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
