// ﷽
// https://codeforces.com/contest/1873/problem/F
// Codeforces -> Codeforces Round 898 (Div. 4) -> F. Money Trees

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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), h(n);
    int ps[n + 1];
    ps[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ps[i + 1] = ps[i] + a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int ans = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        j = max(j, i + 1);
        while (j < n && h[j - 1] % h[j] == 0) j++;
        int s = i - 1, e = j;
        while (e - s > 1) {
            int mid = (s + e) / 2;
            if (ps[mid + 1] - ps[i] <= k) {
                s = mid;
            } else {
                e = mid;
            }
        }

        ans = max(ans, s - i + 1);
    }

    cout << ans << '\n';
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
