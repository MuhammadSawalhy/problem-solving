#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

bool check(int *a, int n) {
    int jj = -1, ps = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    for (int i = 0; i < n; i++) {
        ps += a[i];
        sum -= a[i];
        if (ps == sum) {
            jj = i;
        }
    }

    return jj != -1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], sum += a[i];

    if (sum & 1) {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (sum - a[i] < a[i]) {
            cout << -1 << '\n';
            return;
        }
    }

    if (check(a.data(), n)) {
        cout << "1\n";
        for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
        }
        return;
    }

    int ans[2][n];
    memset(ans, 0, sizeof ans);
    sum -= a[0];
    int i = 1, j = n - 1;
    while (sum > a[0]) {
        debug(i, j);
        assert(i < j);
        int d = min({a[i], a[j], (sum - a[0]) / 2});
        sum -= d * 2;
        a[i] -= d, a[j] -= d;
        ans[0][i] += d, ans[0][j] += d;
        if (a[i] == 0) i++;
        if (a[j] == 0) j--;
    }

    for (int i = 0; i < n; i++) ans[1][i] = a[i];

    cout << 2 << '\n';
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " \n"[j == n - 1];
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("-----", t);
        solve();
    }

    return 0;
}
