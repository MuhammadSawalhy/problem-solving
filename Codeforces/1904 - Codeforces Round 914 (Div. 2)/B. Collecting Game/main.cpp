// ﷽
// https://codeforces.com/contest/1904/problem/B

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
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first, a[i].second = i;
    }

    int ans[n];
    memset(ans, 0, sizeof(ans));
    sort(all(a));

    int sum = 0, j, i = 0;
    while (i < n) {
        sum += a[i].first;
        j = i + 1;
        while (j < n && sum >= a[j].first) {
            sum += a[j++].first;
        }
        for (int k = i; k < j; k++) {
            ans[a[k].second] = j;
        }
        i = j;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] - 1 << " \n"[i == n - 1];
    }
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
