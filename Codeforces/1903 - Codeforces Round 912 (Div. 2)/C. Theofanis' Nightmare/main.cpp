// ﷽
// https://codeforces.com/contest/1903/problem/C

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
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<bool> split(n);
    split[0] = 1;

    for (int i = n - 1; i >= 0; i--) {
        a[i] += a[i + 1];
        if (a[i] > 0) {
            split[i] = 1;
        }
    }

    int ans = 0;
    debug(split);

    for (int i = 0, cnt = 0; i < n; i++) {
        cnt += split[i];
        ans += cnt * (a[i] - a[i + 1]);
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
