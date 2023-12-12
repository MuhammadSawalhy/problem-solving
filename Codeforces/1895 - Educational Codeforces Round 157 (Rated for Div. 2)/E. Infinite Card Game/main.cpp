// ﷽
// https://codeforces.com/contest/1895/problem/E

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

void solve() {
    int n;
    cin >> n;
    pair<int, int> a[n];
    int A[n];
    for (int i = 0; i < n; i++) cin >> a[i].first;
    for (int i = 0; i < n; i++) cin >> a[i].second, A[i] = a[i].second;

    int m;
    cin >> m;
    pair<int, int> b[m];
    for (int i = 0; i < m; i++) cin >> b[i].first;
    for (int i = 0; i < m; i++) cin >> b[i].second;

    sort(a, a + n);
    sort(b, b + m);
    for (int i = n - 2; ~i; i--) maxit(a[i].second, a[i + 1].second);
    for (int i = m - 2; ~i; i--) maxit(b[i].second, b[i + 1].second);

    // returns -1 if can't attack, else returns the max defense
    function<int(int)> getay = [&](int by) {
        int i = upper_bound(a, a + n, make_pair(by, (ll) 1e18)) - a;
        if (i == n) return -1ll;
        return a[i].second;
    };

    function<int(int)> getby = [&](int ay) {
        int i = upper_bound(b, b + m, make_pair(ay, (ll) 1e18)) - b;
        if (i == m) return -1ll;
        return b[i].second;
    };

    // returns -1 if a win, 0 if tie, 1 if b win
    function<int(int)> state = [&](int ay) {
        while (true) {
            int by = getby(ay);
            if (by == -1) return 1;
            int ay2 = getay(by);
            if (ay2 == -1) return -1;
            if (ay2 == ay) return 0;
            ay = ay2;
        }
    };

    sort(A, A + n);

    int s = -1, e = n;
    while (e - s > 1) {
        int i = (s + e) / 2;
        if (state(A[i]) == 1) e = i;
        else s = i;
    }


    int ans[3]{};
    ans[0] = n - e;

    s = -1;
    while (e - s > 1) {
        int i = (s + e) / 2;
        if (state(A[i]) == 0) e = i;
        else s = i;
    }

    ans[1] = n - e - ans[0];
    ans[2] = n - ans[1] - ans[0];

    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
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
