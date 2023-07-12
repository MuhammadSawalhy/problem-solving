// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

void solve() {
    int n, m;
    cin >> n >> m;
    int l[m], r[m];
    for (int i = 0; i < m; i++) {   
        cin >> l[i] >> r[i];
    }

    int q;
    cin >> q;

    vector<int> ones(q);
    for (int i = 0; i < q; i++) {
        cin >> ones[i];
    }

    auto check = [&](int x) {
        vector<int> a(n + 1);

        for (int i = 0; i < x; i++) {
            a[ones[i]] = 1;
        }

        for (int i = 0; i < n; i++) {
            a[i + 1] += a[i];
        }

        for (int i = 0; i < m; i++) {
            if (2 * (a[r[i]] - a[l[i] - 1]) > r[i] - l[i] + 1)
                return true;
        }

        return false;
    };

    int ans = -1, s = 0, e = q + 1;
    while (e - s > 1) {
        int mid = (s + e) / 2;
        if (check(mid)) {
            e = ans = mid;
        } else {
            s = mid;
        }
    }

    cout << ans << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
